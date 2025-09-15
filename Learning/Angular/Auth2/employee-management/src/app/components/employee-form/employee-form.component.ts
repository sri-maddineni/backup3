import { Component, Input, Output, EventEmitter, OnChanges, SimpleChanges } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { EmployeeService, Employee } from '../../services/employee.service';

@Component({
  selector: 'app-employee-form',
  standalone: true,
  imports: [CommonModule, FormsModule],
  templateUrl: './employee-form.component.html',
  styleUrls: ['./employee-form.component.scss']
})
export class EmployeeFormComponent implements OnChanges {
  @Input() employeeToEdit: Employee | null = null;
  @Output() formSubmitted = new EventEmitter<void>();

  employee: Omit<Employee, 'id'> & { id?: number } = {
    name: '',
    email: '',
    position: ''
  };
  errorMessage: string = '';
  successMessage: string = '';

  constructor(private employeeService: EmployeeService) { }

  ngOnChanges(changes: SimpleChanges): void {
    if (changes['employeeToEdit'] && this.employeeToEdit) {
      this.employee = { ...this.employeeToEdit };
      this.errorMessage = '';
      this.successMessage = '';
    } else if (changes['employeeToEdit'] && !this.employeeToEdit) {
      // If employeeToEdit becomes null, reset the form for adding new employee
      this.resetForm();
    }
  }

  onSubmit() {
    this.errorMessage = '';
    this.successMessage = '';

    if (!this.employee.name || !this.employee.email || !this.employee.position) {
      this.errorMessage = 'Please fill in all fields';
      return;
    }

    if (!this.validateEmail(this.employee.email)) {
      this.errorMessage = 'Please enter a valid email address';
      return;
    }

    if (this.employee.id) {
      // Update existing employee
      this.employeeService.updateEmployee(this.employee as Employee);
      this.successMessage = 'Employee updated successfully!';
    } else {
      // Add new employee
      this.employeeService.addEmployee(this.employee);
      this.successMessage = 'Employee added successfully!';
    }

    this.formSubmitted.emit(); // Notify parent component that form was submitted
    this.resetForm();

    // Clear success message after 3 seconds
    setTimeout(() => {
      this.successMessage = '';
    }, 3000);
  }

  onCancelEdit() {
    this.resetForm();
    this.formSubmitted.emit(); // Notify parent to clear employeeToEdit
  }

  private resetForm() {
    this.employee = {
      name: '',
      email: '',
      position: ''
    };
    this.employeeToEdit = null;
    this.errorMessage = '';
    this.successMessage = '';
  }

  private validateEmail(email: string): boolean {
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return emailRegex.test(email);
  }
}
