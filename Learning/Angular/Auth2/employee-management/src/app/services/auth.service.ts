import { Injectable } from '@angular/core';
import { Router } from '@angular/router';
import { BehaviorSubject } from 'rxjs';
import { UserService } from './user.service';

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  private isAuthenticated = new BehaviorSubject<boolean>(false);
  private readonly ADMIN_USERNAME = 'admin';
  private readonly ADMIN_PASSWORD = 'admin123';

  constructor(private router: Router, private userService: UserService) {
    // Check if user is already logged in
    const isLoggedIn = localStorage.getItem('isLoggedIn') === 'true';
    this.isAuthenticated.next(isLoggedIn);
  }

  login(username: string, password: string): boolean {
    // Check for admin credentials first
    if (username === this.ADMIN_USERNAME && password === this.ADMIN_PASSWORD) {
      this.isAuthenticated.next(true);
      localStorage.setItem('isLoggedIn', 'true');
      localStorage.setItem('currentUser', this.ADMIN_USERNAME); // Store admin username
      return true;
    }

    // Check for registered user credentials
    const user = this.userService.getUserByUsername(username);
    if (user && user.password === password) {
      this.isAuthenticated.next(true);
      localStorage.setItem('isLoggedIn', 'true');
      localStorage.setItem('currentUser', username); // Store registered username
      return true;
    }

    return false;
  }

  logout(): void {
    this.isAuthenticated.next(false);
    localStorage.removeItem('isLoggedIn');
    localStorage.removeItem('currentUser');
    this.router.navigate(['/login']);
  }

  isLoggedIn(): boolean {
    return this.isAuthenticated.value;
  }

  getAuthStatus() {
    return this.isAuthenticated.asObservable();
  }

  getCurrentUser(): string | null {
    return localStorage.getItem('currentUser');
  }
}
