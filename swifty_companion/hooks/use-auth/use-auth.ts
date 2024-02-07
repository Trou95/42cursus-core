import AsyncStorage from '@react-native-async-storage/async-storage'
import { AxiosClient, UnAutharizedError } from '../../libs/axios/axios'
import { IUserToken } from '../../auth/interfaces/IUserToken'
import { useContext, useEffect, useState } from 'react'
import { AuthContext } from '../../context/auth-context/auth-context'
import { parseUser } from '../../utils/utils'
import { IUser } from '../../auth/interfaces/IUser'
import CookieManager from '@react-native-cookies/cookies'

export const useAuth = () => {
  const { user, setUser } = useContext(AuthContext)

  useEffect(() => {}, [user])

  const login = async (code: string) => {
    const tokens = await auth(code)
    if (!tokens) throw new Error('Error: Auth')
    setUser(await getUser(tokens.access_token))
    saveStorage(tokens)
  }

  const logout = () => {
    AsyncStorage.removeItem('access_token')
    AsyncStorage.removeItem('refresh_token')
    CookieManager.clearAll(true)
  }

  const getUser = async (access_token: string) => {
    try {
      const user = (await getMe(access_token)).data
      return parseUser(user)
    } catch (e: any) {
      const refresh_token = await getRefreshToken()
      if (!refresh_token) throw new Error('Error: Refresh token not found')

      const tokens = await AxiosClient.refresh_token(refresh_token)
      if (!tokens) throw new Error('Error: Refresh Token')
      saveStorage(tokens)

      const user = (await getMe(access_token)).data
      return parseUser(user)
    }
  }

  const auth = async (code: string) => {
    try {
      const token: IUserToken = (await AxiosClient.auth(code))?.data
      return token
    } catch (e) {}
  }

  const getMe = async (token: string) => {
    return await AxiosClient.get('/v2/me', {
      Authorization: `Bearer ${token}`,
    })
  }

  const saveStorage = (tokens: IUserToken) => {
    setAccessToken(tokens.access_token)
    setRefreshToken(tokens.refresh_token)
  }

  const clearStorage = () => {
    console.log('Clear Storage')
    AsyncStorage.clear()
  }

  const getAccessToken = async () => {
    return getStorageItem('access_token')
  }

  const setAccessToken = async (token: string | undefined) => {
    console.log('SetAccessToken:', token)
    await setStorageItem('access_token', token)
  }

  const getRefreshToken = async () => {
    return await getStorageItem('refresh_token')
  }

  const setRefreshToken = async (token: string | undefined) => {
    await setStorageItem('refresh_token', token)
  }

  const getStorageItem = async (key: string) => {
    return await AsyncStorage.getItem(key)
  }

  const setStorageItem = async (key: string, value: string | undefined) => {
    if (!value) return
    try {
      await AsyncStorage.setItem(key, value)
    } catch (e) {
      console.log(e)
    }
  }

  return {
    user,
    getUser,
    getAccessToken,
    setAccessToken,
    getRefreshToken,
    setRefreshToken,
    clearStorage,
    login,
    logout,
  }
}
