import React from 'react'
import Animated, {
  Easing,
  useAnimatedStyle,
  useSharedValue,
  withRepeat,
  withTiming,
} from 'react-native-reanimated'
import { StyleSheet, View } from 'react-native'
import 'react-native-gesture-handler'
import { height } from '@fortawesome/free-solid-svg-icons/faLocationDot'

export const Spinner = ({ size, color }) => {
  const sv = useSharedValue(0)

  React.useEffect(() => {
    sv.value = withRepeat(
      withTiming(1, { duration: 1000, easing: Easing.linear }),
      -1
    )
  }, [])

  const animatedStyle = useAnimatedStyle(() => ({
    transform: [{ rotateZ: `${sv.value * 360}deg` }],
    borderLeftColor: color,
    borderRightColor: '#212121',
    borderTopColor: '#212121',
    borderBottomColor: '#212121',
  }))

  return (
    <View style={styles.container}>
      <Animated.View
        style={[
          {
            ...styles.spinner,
            width: size,
            height: size,
            borderRadius: size / 2,
          },
          ,
          animatedStyle,
        ]}
      />
    </View>
  )
}

const styles = StyleSheet.create({
  spinner: {
    borderWidth: 2,
    borderTopColor: '#f5f5f5',
    borderRightColor: '#f5f2f5',
    borderBottomColor: '#f5f5f5',
    borderLeftColor: 'blue',
  },
})
