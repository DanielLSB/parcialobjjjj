#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;
class Empleado1 : public Persona {
	// atributos
private: string id_puesto, fecha_inicio_labores, fecha_ingreso;
	   // constructor
public:
	Empleado1() {
	}
	Empleado1(string nom, string ape, string dir, int tel, string dp, int gn, string fn, string puesto, string inicio, string ingreso) : Persona(nom, ape, dir, tel, dp, gn, fn) {
		id_puesto = puesto;
		fecha_inicio_labores = inicio;
		fecha_ingreso = ingreso;



	}

	// METODOS
	//set (modificar)
	void setId_puesto(string puesto) { id_puesto = puesto; }
	void setFecha_inicio(string inicio) { fecha_inicio_labores = inicio; }
	void setFecha_ingreso(string ingreso) { fecha_ingreso = ingreso; }

	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }






	//get (mostrar)
	string getId_puesto() { return id_puesto; }
	string getFecha_inicio() { return fecha_inicio_labores; }
	string getFecha_ingreso() { return fecha_ingreso; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }






	// metodo

	void dele(int id_aux) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();




		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id1 = to_string(id_aux);
			string ss;
			cout << "---------------------------------------------------" << endl;

			ss = "DELETE FROM empleados WHERE id_empleado= " + id1 + " ";
			string query = ss.c_str();
			const char* q = query.c_str();
			q_estado = mysql_query(cn.getConectar(), q);
			if (!q_estado)
			{
				cout << "REGISTRO ELIMINADO. . ." << endl;
			}
			else
			{
				cout << "ERROR. . ." << endl;
			}



		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}


	void update(int id_aux2) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conexion Exitosa..." << endl;

			string id2 = to_string(id_aux2);
			string t = to_string(telefono);
			string g = to_string(genero);
			string update;
			cout << "---------------------------------------------------" << endl;

			update = "UPDATE empleados SET nombres ='" + nombres + "' , apellidos = '" + apellidos + "',direccion ='" + direccion + "' ,telefono =" + t + " ,dpi ='" + dpi + "' ,genero =" + g + " ,fecha_nacimiento ='" + fecha_nacimiento + "' ,id_puesto='" + id_puesto + "' ,fecha_inicio_labores ='" + fecha_inicio_labores + "' ,feha_ingreso ='" + fecha_ingreso + "' WHERE id_empleado =" + id2 + " ";
			string query = update.c_str();
			const char* q = query.c_str();
			q_estado = mysql_query(cn.getConectar(), q);
			if (!q_estado)
			{
				cout << "actualizado. . ." << endl;
			}
			else
			{
				cout << "error en la actualizacion. . ." << endl;
			}



		}
		else {
			cout << "error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string g = to_string(genero);

			string insert = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,dpi,genero,fecha_nacimiento,id_puesto,fecha_inicio_labores,feha_ingreso) VALUES('" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + dpi + "'," + g + ",'" + fecha_nacimiento + "','" + id_puesto + "','" + fecha_inicio_labores + "','" + fecha_ingreso + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				cout << "ingreso exitoso...." << endl;
			}
			else {
				cout << "error al ingresar..." << endl;
			}


		}
		else {
			cout << "error en la conexion" << endl;


		}
		cn.cerrar_conexion();


	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10] << "," << fila[11] << endl;


				}
			}

			else {
				cout << " xxx Error al ingresar informacion xxxx" << endl;
			}

		}
		else {
			cout << "error en la conexion" << endl;


		}
		cn.cerrar_conexion();

	}
};

