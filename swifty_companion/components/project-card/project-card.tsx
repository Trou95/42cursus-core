import React from 'react'
import { View, Text } from 'react-native'
import { FontAwesomeIcon } from '@fortawesome/react-native-fontawesome'
import { faCircleCheck } from '@fortawesome/free-solid-svg-icons'
import { Project } from '../../screens/projects/project'

enum ProjectStatus {
  FINISHED = 'finished',
  IN_PROGRESS = 'in_progress',
  FAIL = 'failed',
  SEARCING_GROUP = 'searching_a_group',
}

const colors = {
  [ProjectStatus.FINISHED]: 'bg-green-500',
  [ProjectStatus.IN_PROGRESS]: 'bg-blue-500',
  [ProjectStatus.FAIL]: 'bg-red-500',
  [ProjectStatus.SEARCING_GROUP]: 'bg-yellow-500',
}

export interface IProjectCardInfo {
  status: string
  name: string
}

export const ProjectCard = ({
  projectInfo,
}: {
  projectInfo: IProjectCardInfo
}) => {
  return (
    <View className="bg-black w-full h-24 m-1 rounded-xl">
      <View className="flex flex-row h-full">
        <View
          className={
            'flex basis-1/6 justify-center items-center ' +
            (colors[projectInfo.status] || 'bg-indigo-500')
          }
        >
          <FontAwesomeIcon icon={faCircleCheck} size={50} color="#FFF" />
        </View>
        <View className="flex basis-5/6 justify-center items-center">
          <Text className="text-lg text-white">{projectInfo.name}</Text>
        </View>
      </View>
    </View>
  )
}
