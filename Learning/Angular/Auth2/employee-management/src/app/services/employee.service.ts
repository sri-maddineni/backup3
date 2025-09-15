import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs';

export interface Employee {
  id: number;
  name: string;
  email: string;
  position: string;
}

@Injectable({
  providedIn: 'root'
})
export class EmployeeService {
  private employees = new BehaviorSubject<Employee[]>([]);
  private readonly STORAGE_KEY = 'employees';

  constructor() {
    // Load employees from localStorage
    const storedEmployees = localStorage.getItem(this.STORAGE_KEY);
    if (storedEmployees) {
      this.employees.next(JSON.parse(storedEmployees));
    }
  }

  getEmployees() {
    return this.employees.asObservable();
  }

  addEmployee(employee: Omit<Employee, 'id'>) {
    const currentEmployees = this.employees.value;
    const newEmployee = {
      ...employee,
      id: currentEmployees.length > 0
        ? Math.max(...currentEmployees.map(e => e.id)) + 1
        : 1
    };

    const updatedEmployees = [...currentEmployees, newEmployee];
    this.employees.next(updatedEmployees);
    localStorage.setItem(this.STORAGE_KEY, JSON.stringify(updatedEmployees));
    return newEmployee;
  }

  updateEmployee(employee: Employee) {
    const currentEmployees = this.employees.value;
    const index = currentEmployees.findIndex(e => e.id === employee.id);

    if (index !== -1) {
      const updatedEmployees = [...currentEmployees];
      updatedEmployees[index] = employee;
      this.employees.next(updatedEmployees);
      localStorage.setItem(this.STORAGE_KEY, JSON.stringify(updatedEmployees));
      return true;
    }
    return false;
  }

  deleteEmployee(id: number) {
    const currentEmployees = this.employees.value;
    const updatedEmployees = currentEmployees.filter(e => e.id !== id);
    this.employees.next(updatedEmployees);
    localStorage.setItem(this.STORAGE_KEY, JSON.stringify(updatedEmployees));
  }
}
