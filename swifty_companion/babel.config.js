module.exports = {
  presets: ['module:@react-native/babel-preset'],
  plugins: [
    'nativewind/babel',
    'react-native-reanimated/plugin',
    [
      'module:react-native-dotenv',
      {
        envNAME: 'APP_ENV',
        moduleNAME: '@env',
        path: '.env',
      },
    ],
  ],
}
