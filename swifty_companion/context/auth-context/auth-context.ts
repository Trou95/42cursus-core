import { createContext, useContext } from 'react'
import { IUser } from '../../auth/interfaces/IUser'

interface AuthContext {
  user: IUser | null
  setUser: (user: IUser | null) => void
}

export const AuthContext = createContext<AuthContext>({
  user: null,
  setUser: () => {},
})
