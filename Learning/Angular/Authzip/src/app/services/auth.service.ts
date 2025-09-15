import { Injectable, PLATFORM_ID, Inject } from '@angular/core';
import { Router } from '@angular/router';
import { isPlatformBrowser } from '@angular/common';

interface User {
  email: string;
  password: string;
}

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  private readonly USERS_KEY = 'users';
  private readonly CURRENT_USER_KEY = 'currentUser';
  private storage: Storage | null = null;

  constructor(
    private router: Router,
    @Inject(PLATFORM_ID) private platformId: Object
  ) {
    if (isPlatformBrowser(this.platformId)) {
      this.storage = window.localStorage;
      // Initialize users array in localStorage if it doesn't exist
      if (!this.storage.getItem(this.USERS_KEY)) {
        this.storage.setItem(this.USERS_KEY, JSON.stringify([]));
      }
    }
  }

  private getItem(key: string): string | null {
    return this.storage?.getItem(key) || null;
  }

  private setItem(key: string, value: string): void {
    this.storage?.setItem(key, value);
  }

  private removeItem(key: string): void {
    this.storage?.removeItem(key);
  }

  signup(email: string, password: string): boolean {
    if (!this.storage) return false;

    const users: User[] = JSON.parse(this.getItem(this.USERS_KEY) || '[]');

    // Check if user already exists
    if (users.some(user => user.email === email)) {
      return false;
    }

    // Add new user
    users.push({ email, password });
    this.setItem(this.USERS_KEY, JSON.stringify(users));
    return true;
  }

  login(email: string, password: string): boolean {
    if (!this.storage) return false;

    const users: User[] = JSON.parse(this.getItem(this.USERS_KEY) || '[]');
    const user = users.find(u => u.email === email && u.password === password);

    if (user) {
      this.setItem(this.CURRENT_USER_KEY, JSON.stringify(user));
      return true;
    }
    return false;
  }

  logout(): void {
    if (!this.storage) return;

    this.removeItem(this.CURRENT_USER_KEY);
    this.router.navigate(['/login']);
  }

  isLoggedIn(): boolean {
    if (!this.storage) return false;
    return !!this.getItem(this.CURRENT_USER_KEY);
  }

  getCurrentUser(): User | null {
    if (!this.storage) return null;

    const userStr = this.getItem(this.CURRENT_USER_KEY);
    return userStr ? JSON.parse(userStr) : null;
  }
}
