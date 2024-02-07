import React, { useEffect } from 'react'
import Animated, {
  Easing,
  useAnimatedStyle,
  useSharedValue,
  withRepeat,
  withTiming,
} from 'react-native-reanimated'
import { StyleSheet, View, Text, Image } from 'react-native'
import 'react-native-gesture-handler'
import { Spinner } from '../../components/spinner/spinner'
import { SafeAreaView } from 'react-native-safe-area-context'

export const Splash = ({ navigation } : {navigation: any}) => {
  useEffect(() => {
    console.log('Splash')
    setTimeout(() => {
      navigation.push('Login')
    }, 2000)
  }, [])

  return (
    <SafeAreaView className="w-full h-screen bg-blue-500">
      <View className="h-screen flex justify-center items-center">
        <Image
          style={{ width: 100, height: 100 }}
          source={require('./images/logo.png')}
        />
        <View className="w-[50%] h-0.5 bg-white mb-2"></View>
        <Text className="text-white font-bold mb-2">Swifty Companion</Text>
        <Spinner color={'white'} size={24} />
      </View>
    </SafeAreaView>
  )
}
