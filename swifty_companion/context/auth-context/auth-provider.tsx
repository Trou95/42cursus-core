import React, { useContext, useEffect, useState } from 'react'
import { AuthContext } from './auth-context'
import { IUser } from '../../auth/interfaces/IUser'
import { useAuth } from '../../hooks/use-auth/use-auth'

export const AuthProvider = ({ children }: any) => {
  const [user, setUser] = useState(null)

  return (
    <AuthContext.Provider value={{ user, setUser }}>
      {children}
    </AuthContext.Provider>
  )
}
