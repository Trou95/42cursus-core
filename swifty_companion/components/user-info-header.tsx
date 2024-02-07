import React, { useContext } from 'react'
import { faAngleLeft, faLocationDot } from '@fortawesome/free-solid-svg-icons'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import {
  Image,
  ImageBackground,
  View,
  Text,
  TouchableOpacity,
} from 'react-native'
import { AuthContext } from '../context/auth-context/auth-context'

export const UserInfoHeader = ({ navigation }) => {
  const { user } = useContext(AuthContext)

  return (
    <View className="flex flex-row">
      <ImageBackground
        source={require('./user-info-header/images/background.jpg')}
        resizeMode="cover"
        className="w-full h-40 flex justify-center items-center"
      >
        <View className="w-24 h-24 border-2 border-green-400 rounded-full p-1 mb-1 relative z-1">
          <Image
            source={{ uri: user.avatar }}
            className="w-full h-full rounded-full"
          />
        </View>
        <Text className="font-bold mb-0.5 text-white">Gorkem Demirtaş</Text>
        <View className="flex items-center flex-row text-white">
          <FontAwesomeIcon icon={faLocationDot} color="white" />
          <Text className="text-white">Istanbul</Text>
        </View>
      </ImageBackground>
    </View>
  )
}
