import React, { useCallback, useContext } from 'react'
import {
  Text,
  View,
  SafeAreaView,
  ScrollView,
  BackHandler,
  FlatList,
} from 'react-native'
import { UserInfoHeader } from '../../components/user-info-header'
import { ProjectCard } from '../../components/project-card/project-card'
import { AuthContext } from '../../context/auth-context/auth-context'
import { useNavigationState } from '@react-navigation/native'

export const Project = ({ navigation }) => {
  const { user } = useContext(AuthContext)

  return (
    <SafeAreaView className="h-screen">
      <UserInfoHeader navigation={navigation} />
      <Text className="text-black text-lg bg-green-400 p-2">Projects</Text>
      <FlatList
        data={user?.projects}
        renderItem={(project) => (
          <View className="px-3">
            <ProjectCard
              projectInfo={{
                status: project.item.status,
                name: project.item.name,
              }}
            />
          </View>
        )}
      />
    </SafeAreaView>
  )
}
