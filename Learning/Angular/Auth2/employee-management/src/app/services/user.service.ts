import { Injectable } from '@angular/core';

export interface User {
  username: string;
  password: string;
}

@Injectable({
  providedIn: 'root'
})
export class UserService {
  private readonly USERS_STORAGE_KEY = 'registeredUsers';

  constructor() { }

  private getUsers(): User[] {
    const usersString = localStorage.getItem(this.USERS_STORAGE_KEY);
    return usersString ? JSON.parse(usersString) : [];
  }

  private saveUsers(users: User[]): void {
    localStorage.setItem(this.USERS_STORAGE_KEY, JSON.stringify(users));
  }

  registerUser(user: User): boolean {
    const users = this.getUsers();
    if (users.some(u => u.username === user.username)) {
      return false; // User already exists
    }
    users.push(user);
    this.saveUsers(users);
    return true;
  }

  getUserByUsername(username: string): User | undefined {
    const users = this.getUsers();
    return users.find(u => u.username === username);
  }
}
