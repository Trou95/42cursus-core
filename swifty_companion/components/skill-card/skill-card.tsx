import React from 'react'
import { View, Text } from 'react-native'
import { IUserSkill } from '../../auth/interfaces/IUserSkill'

export const SkillCard = ({ skill }: { skill: IUserSkill }) => {
  return (
    <>
      <View className="bg-slate-900 w-40 h-24 m-2 rounded-lg flex justify-center items-center">
        <Text className="text-sm text-center text-white">{skill.name}</Text>
        <View className="border-4 border-yellow-300 rounded-full w-14 h-14 m-1 flex justify-center items-center text-white">
          <Text className="text-sm text-white">
            {Math.round(skill.level * 100) / 100}
          </Text>
        </View>
      </View>
    </>
  )
}
