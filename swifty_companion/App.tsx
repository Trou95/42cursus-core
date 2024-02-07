import React, { useContext, useEffect, useState } from 'react'
import {
  BackHandler,
  Button,
  SafeAreaView,
  Text,
  TouchableOpacity,
} from 'react-native'
import { WebView } from 'react-native-webview'
import { IUserToken } from './auth/interfaces/IUserToken'
import { Login } from './screens/login/login'
import { View } from 'react-native'
import {
  NavigationContainer,
  useNavigationState,
} from '@react-navigation/native'
import { createNativeStackNavigator } from '@react-navigation/native-stack'
import { Home } from './screens/home/home'
import { Project } from './screens/projects/project'
import { IUser } from './auth/interfaces/IUser'
import { AuthContext } from './context/auth-context/auth-context'
import { user } from '@nextui-org/react'
import { AuthProvider } from './context/auth-context/auth-provider'
import { useAuth } from './hooks/use-auth/use-auth'
import { Splash } from './screens/splash/splash'
import 'react-native-gesture-handler'

const Stack = createNativeStackNavigator()

export default function App() {
  const [code, setCode] = useState<any>(undefined)

  const { getAccessToken, setAccessToken, login } = useAuth()

  const apiUrl =
    'https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-4429bf366ad8c4ed916c245b37016b86b6c9674af8518b7ec528422936eec488&redirect_uri=https%3A%2F%2Fintra.localhost&response_type=code'

  return (
    <AuthProvider>
      <NavigationContainer>
        <Stack.Navigator screenOptions={{ headerShown: false }}>
          <Stack.Screen name="Splash" component={Splash} />
          <Stack.Screen name="Login" component={Login} />
          <Stack.Screen name="Home" component={Home} />
          <Stack.Screen name="Projects" component={Project} />
        </Stack.Navigator>
      </NavigationContainer>
    </AuthProvider>
  )
}
