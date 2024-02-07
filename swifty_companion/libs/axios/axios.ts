import { config } from '@fortawesome/fontawesome-svg-core'
import axios, { Axios, AxiosError, AxiosHeaders, AxiosResponse } from 'axios'
import { IUserToken } from '../../auth/interfaces/IUserToken'
import { REACT_APP_CLIENT_ID, REACT_APP_CLIENT_SECRET } from '@env'

export class UnAutharizedError {
  constructor(readonly status: number, readonly message: string) {}
}

export class AxiosClient {
  private static instance: Axios = axios.create({
    baseURL: 'https://api.intra.42.fr',
  })

  static async get(url: string, headers?: any) {
    try {
      return await AxiosClient.instance.get(url, {
        headers,
      })
    } catch (e: any) {
      throw new UnAutharizedError(e.response.status, e.response.data.message)
    }
  }

  static async post(url: string, data?: any, headers?: any) {
    try {
      return await AxiosClient.instance.post(url, data, headers)
    } catch (e: any) {
      console.log(e.response.data)
    }
  }

  static async auth(code: string) {
    try {
      return this.post('/oauth/token', {
        grant_type: 'authorization_code',
        client_id: REACT_APP_CLIENT_ID,
        client_secret: REACT_APP_CLIENT_SECRET,
        code: code,
        redirect_uri: 'https://intra.localhost',
      })
    } catch (e) {
      console.log('AxiosClient: ', e)
    }
  }

  static async refresh_token(refresh_token: string) {
    try {
      return (
        await this.post('/oauth/token', {
          grant_type: 'refresh_token',
          client_id: REACT_APP_CLIENT_ID,
          client_secret: REACT_APP_CLIENT_SECRET,
          refresh_token,
          redirect_uri: 'https://intra.localhost',
        })
      )?.data
    } catch (e) {
      console.log('AxiosClient: ', e)
    }
  }
}
