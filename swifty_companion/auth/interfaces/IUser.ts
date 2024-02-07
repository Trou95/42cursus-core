import { IUserProject } from './IUserProject'
import { IUserSkill } from './IUserSkill'
import { IUserToken } from './IUserToken'

export interface IUser {
  id: number
  login: string
  full_name: string
  email: string
  avatar: string
  wallet: number
  level: number
  campus: string
  skills?: IUserSkill[]
  projects?: IUserProject[]
  token?: IUserToken
}
