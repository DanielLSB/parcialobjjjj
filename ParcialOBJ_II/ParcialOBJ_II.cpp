// ParcialOBJ_II.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Empleado1.h"
#include "puesto.h"
using namespace std;
int q_estado;
int main() {
	string nombres, apellidos, direccion, dpi, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso;
	string puesto;
	int telefono = 0;
	int genero = 0;
	int id_auxp = 0;
	int id_auxp1 = 0;
	int id_aux2 = 0;
	int id_aux = 0;
	int op = 0;

	int op1 = 0;

	do {
		cout << "-----------------menu-----------------" << endl;
		cout << "1. empleados" << endl;
		cout << "2. puestos" << endl;
		cout << "3.salir" << endl;
		cout << "ingrese su opcion: "; cin >> op; cin.ignore();
		switch (op) {

		case 1:
			do {
				system("cls");
				cout << "1. INGRESAR" << endl;
				cout << "2. MOSTRAR" << endl;
				cout << "3. ELIMINAR" << endl;
				cout << "4. ACTUALIZAR" << endl;
				cout << "5. SALIR" << endl;

				cout << "ingrese su opcion: "; cin >> op1; cin.ignore();
				if (op1 == 1) {
					system("cls");
					cout << "ingrese sus nombres:" << endl;
					getline(cin, nombres);
					cout << "ingrese sus apellidos:" << endl;
					getline(cin, apellidos);
					cout << "ingrese direccion:" << endl;
					getline(cin, direccion);
					cout << "ingrese telefono" << endl;
					cin >> telefono;
					cin.ignore();
					cout << "ingrese dpi" << endl;
					getline(cin, dpi);
					cout << "ingrese genero hombre=0 mujer =1 :" << endl;
					cin >> genero;
					cin.ignore();
					cout << "ingrese fecha de nacimiento" << endl;
					getline(cin, fecha_nacimiento);
					cout << "ingrese id_puesto" << endl;
					getline(cin, id_puesto);
					cout << "ingrese fecha de inicio de labores" << endl;
					getline(cin, fecha_inicio_labores);
					cout << "ingrese ingreso" << endl;
					getline(cin, fecha_ingreso);


					Empleado1 c = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c.crear();
					system("pause");
				}
				if (op1 == 2) {
					system("cls");
					Empleado1 c = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c.leer();
					system("pause");
				}
				if (op1 == 3) {
					system("cls");
					Empleado1 c = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					cout << "ingrese el id del registro a eliminar: "; cin >> id_aux;
					c.dele(id_aux);
					system("pause");
				}
				if (op1 == 4) {
					system("cls");
					cout << "ingrese id del registro a modificar: "; cin >> id_aux2; cin.ignore();
					cout << "ingrese sus nombres:" << endl;
					getline(cin, nombres);
					cout << "ingrese sus apellidos:" << endl;
					getline(cin, apellidos);
					cout << "ingrese direccion:" << endl;
					getline(cin, direccion);
					cout << "ingrese telefono" << endl;
					cin >> telefono;
					cin.ignore();
					cout << "ingrese dpi" << endl;
					getline(cin, dpi);
					cout << "ingrese genero hombre=0 mujer =1 :" << endl;
					cin >> genero;
					cin.ignore();
					cout << "ingrese fecha de nacimiento" << endl;
					getline(cin, fecha_nacimiento);
					cout << "ingrese id_puesto" << endl;
					getline(cin, id_puesto);
					cout << "ingrese fecha de inicio de labores" << endl;
					getline(cin, fecha_inicio_labores);
					cout << "ingrese ingreso" << endl;
					getline(cin, fecha_ingreso);

					Empleado1 c1 = Empleado1(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_labores, fecha_ingreso);
					c1.update(id_aux2);
					system("pause");

				}
				if (op1 == 5) { system("cls"); main(); }
			} while (op <= 5);
			break;

		case 2:
			do {
				system("cls");
				cout << "1. INGRESAR" << endl;
				cout << "2. MOSTRAR" << endl;
				cout << "3. ELIMINAR" << endl;
				cout << "4. ACTUALIZAR" << endl;
				cout << "5. SALIR" << endl;

				cout << "ingrese su opcion: "; cin >> op1; cin.ignore();

				if (op1 == 1) {
					system("cls");
					cout << "ingrese un puesto: ";
					getline(cin, puesto);

					Puesto p = Puesto(puesto);
					p.crear1();
					system("pause");
				}
				if (op1 == 2) {
					system("cls");
					Puesto p = Puesto(puesto);
					p.leer1();
					system("pause");
				}
				if (op1 == 3) {
					system("cls");
					cout << "ingrese el id del registro a eliminar: "; cin >> id_auxp;
					Puesto p = Puesto(puesto);
					p.deletep(id_auxp);
					system("pause");
				}
				if (op1 == 4) {
					system("cls");
					cout << "ingrese el id del registro a actualizar: "; cin >> id_auxp1; cin.ignore();
					cout << "ingrese el nuevo puesto" << endl;
					getline(cin, puesto);
					Puesto p1 = Puesto(puesto);
					p1.updatep(id_auxp1);
					system("pause");
				}
				if (op1 == 5) { system("cls"); main(); }
			} while (op <= 5);
			break;
		}
	} while (op <= 2);

	system("pause");
	return 0;
}