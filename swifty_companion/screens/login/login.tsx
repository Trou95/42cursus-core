import React, { useContext, useEffect, useState } from 'react'
import { SafeAreaView, Text, TouchableOpacity, View } from 'react-native'
import WebView from 'react-native-webview'
import { useAuth } from '../../hooks/use-auth/use-auth'
import { AuthContext } from '../../context/auth-context/auth-context'
import { Spinner } from '../../components/spinner/spinner'

export const Login = ({ navigation }: { navigation: any }) => {
  const [code, setCode] = useState(undefined)
  const [isLoaded, setIsLoaded] = useState(false)

  const { login, getUser, getAccessToken, clearStorage } = useAuth()

  const { setUser } = useContext(AuthContext)

  const apiUrl =
    'https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-4429bf366ad8c4ed916c245b37016b86b6c9674af8518b7ec528422936eec488&redirect_uri=https%3A%2F%2Fintra.localhost&response_type=code'

  const handleNavState = (navState: any) => {
    if (navState.url.indexOf('?code=') > -1) {
      const tmp = navState.url.substring(navState.url.indexOf('code=') + 5)
      console.log('NavState Code:', tmp)
      setCode(tmp)
    }
  }

  const handleLogin = () => {
    if (code) {
      setIsLoaded(false)
      login(code).then(() => {
        navigation.push('Home')
      })
    }
  }

  useEffect(() => {
    console.log('Screen: Login')
    getAccessToken()
      .then(async (token) => {
        if (token) {
          console.log('Token Found: ', token)
          setUser(await getUser(token))
          navigation.push('Home')
        } else if (code) {
          handleLogin()
        }
      })
      .catch((e) => {
        clearStorage()
        navigation.push('Login')
      })
  }, [code])

  return (
    <SafeAreaView className="flex-1">
      {!isLoaded && (
        <View className="w-full h-screen flex justify-center items-center">
          <Spinner color={'white'} size={24} />
        </View>
      )}
      {!code && (
        <WebView
          source={{ uri: apiUrl }}
          style={{ flex: 1 }}
          onLoad={() => setIsLoaded(true)}
          onNavigationStateChange={handleNavState}
        />
      )}
    </SafeAreaView>
  )
}
