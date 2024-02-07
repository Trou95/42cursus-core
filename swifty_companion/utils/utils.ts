import { IUser } from '../auth/interfaces/IUser'
import { IUserProject } from '../auth/interfaces/IUserProject'

export const parseUser = (data: any): IUser => {
  const cursus_users = data.cursus_users[1]
  return {
    id: cursus_users.user.id,
    login: cursus_users.user.login,
    email: cursus_users.user.email,
    full_name: cursus_users.user.displayname,
    avatar: cursus_users.user.image.link,
    wallet: cursus_users.user.wallet,
    level: cursus_users.level,
    campus: data.campus[0].name,
    skills: cursus_users.skills,
    projects: parseUserProjects(data.projects_users),
  }
}

const parseUserProjects = (data: any): IUserProject[] => {
  const response: IUserProject[] = data.map((project) => {
    return {
      id: project.project.id,
      final_mark: project.final_mark,
      status: project.status,
      name: project.project.name,
      slug: project.project.slug,
    }
  })
  return response
}
