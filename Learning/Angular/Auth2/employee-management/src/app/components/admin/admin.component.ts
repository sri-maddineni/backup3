import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Router } from '@angular/router';
import { AuthService } from '../../services/auth.service';
import { EmployeeFormComponent } from '../employee-form/employee-form.component';
import { EmployeeListComponent } from '../employee-list/employee-list.component';
import { Employee } from '../../services/employee.service';

@Component({
  selector: 'app-admin',
  standalone: true,
  imports: [CommonModule, EmployeeFormComponent, EmployeeListComponent],
  templateUrl: './admin.component.html',
  styleUrls: ['./admin.component.scss']
})
export class AdminComponent {
  employeeToEdit: Employee | null = null;

  constructor(
    private authService: AuthService,
    private router: Router
  ) { }

  logout() {
    this.authService.logout();
  }

  onEditEmployee(employee: Employee) {
    this.employeeToEdit = employee;
  }

  onEmployeeFormSubmitted() {
    this.employeeToEdit = null; // Clear the employeeToEdit after form submission (add or update)
  }
}
