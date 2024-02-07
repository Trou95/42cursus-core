import React, { useContext, useEffect } from 'react'
import {
  Text,
  View,
  Image,
  ImageBackground,
  FlatList,
  ScrollView,
  TouchableOpacity,
  Button,
  BackHandler,
} from 'react-native'
import { SafeAreaView } from 'react-native-safe-area-context'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import { faLocationDot } from '@fortawesome/free-solid-svg-icons/faLocationDot'
import { faAngleLeft } from '@fortawesome/free-solid-svg-icons/faAngleLeft'
import { faAngleRight } from '@fortawesome/free-solid-svg-icons/faAngleRight'
import { faCircleUser } from '@fortawesome/free-solid-svg-icons/faCircleUser'
import { faEnvelope } from '@fortawesome/free-solid-svg-icons/faEnvelope'
import { faWallet } from '@fortawesome/free-solid-svg-icons/faWallet'
import { faRankingStar } from '@fortawesome/free-solid-svg-icons/faRankingStar'
import { faArrowRightFromBracket } from '@fortawesome/free-solid-svg-icons/faArrowRightFromBracket'

import { UserInfoHeader } from '../../components/user-info-header'
import { AuthContext } from '../../context/auth-context/auth-context'

import { SkillCard } from '../../components/skill-card/skill-card'
import { useNavigationState } from '@react-navigation/native'
import { useAuth } from '../../hooks/use-auth/use-auth'

export const Home = ({ navigation }: any) => {
  const { user } = useContext(AuthContext)

  const { logout } = useAuth()

  const screenName = useNavigationState(
    (state) => state.routes[state.index].name
  )

  BackHandler.addEventListener('hardwareBackPress', () => {
    console.log('Screen', screenName)
    if (screenName === 'Projects') {
      navigation.navigate('Home')
      return false
    } else {
      return true
    }
  })

  return (
    <SafeAreaView className="w-full h-screen">
      <ScrollView>
        <UserInfoHeader navigation={navigation} />
        <View className="w-full p-2">
          <View className="bg-slate-900 mt-1 p-5 rounded-xl flex flex-row animate-pulse">
            <View className="flex basis-1/6 justify-center">
              <FontAwesomeIcon icon={faCircleUser} size={24} color="#FFF" />
            </View>
            <View>
              <Text className="font-bold text-white">USERNAME</Text>
              <Text className="text-white">{user?.login}</Text>
            </View>
          </View>
          <View className="bg-slate-900 mt-1 p-5 rounded-xl flex flex-row">
            <View className="flex basis-1/6 justify-center">
              <FontAwesomeIcon icon={faEnvelope} size={24} color="#FFF" />
            </View>
            <View>
              <Text className="font-bold text-white">EMAIL</Text>
              <Text className="text-white">{user?.email}</Text>
            </View>
          </View>
          <View className="bg-slate-900 mt-1 p-5 rounded-xl flex flex-row">
            <View className="flex basis-1/6 justify-center">
              <FontAwesomeIcon icon={faWallet} size={24} color="#FFF" />
            </View>
            <View>
              <Text className="font-bold text-white">WALLET</Text>
              <Text className="text-white">{user?.wallet}</Text>
            </View>
          </View>
          <View className="bg-slate-900 mt-1 p-5 rounded-xl flex flex-row">
            <View className="flex basis-1/6 justify-center">
              <FontAwesomeIcon icon={faRankingStar} size={24} color="#FFF" />
            </View>
            <View>
              <Text className="font-bold text-white">LEVEL</Text>
              <Text className="text-white">{user?.level}</Text>
            </View>
          </View>
          <View className=" bg-slate-900 mt-1 p-5 rounded-xl flex flex-row">
            <View className="flex basis-1/6 justify-center">
              <FontAwesomeIcon icon={faCircleUser} size={24} color="#FFF" />
            </View>
            <View className="flex basis-4/6 justify-self-start items-start self-start justify-center ">
              <Text className="font-bold text-white">PROJECTS</Text>
              <Text className="text-white">{user?.projects?.length}</Text>
            </View>
            <View className="basis-1/6 justify-center items-end">
              <TouchableOpacity
                className="p-2 "
                onPress={() => {
                  navigation.push('Projects')
                }}
              >
                <FontAwesomeIcon icon={faAngleRight} size={24} color="#FFF" />
              </TouchableOpacity>
            </View>
          </View>
          <View className="bg-cyan-900 mt-1 p-5 rounded-xl flex flex-row">
            <View className="flex flex-row w-full justify-end items-center">
              <Text className="font-bold text-white px-2">LOGOUT</Text>
              <TouchableOpacity
                className="p-2 "
                onPress={() => {
                  console.log('Home Logout')
                  logout()
                  navigation.push('Splash')
                }}
              >
                <FontAwesomeIcon
                  icon={faArrowRightFromBracket}
                  size={24}
                  color="#FFF"
                />
              </TouchableOpacity>
            </View>
          </View>
        </View>

        <View className="w-full h-fit flex flex-row flex-wrap justify-center">
          {user?.skills?.map((skill) => (
            <SkillCard key={skill.id} skill={skill} />
          ))}
        </View>
      </ScrollView>
    </SafeAreaView>
  )
}
