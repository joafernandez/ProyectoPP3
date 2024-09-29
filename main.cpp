#include <iostream>
#include <vector>
#include "Empleado.h"
#include "Desarrollador.h"
#include "Tester.h"
#include "GerenteProyecto.h"
#include "Proyecto.h"
#include "Tarea.h"
#include "Cliente.h"
#include "ReunionSeguimiento.h"
#include "Reporte .h"

using namespace std;

int main() {
    // Precargar datos de ejemplo
    vector<Empleado*> empleados = {
            new Desarrollador("Juan", "Desarrollador", "C++"),
            new Desarrollador("Pedro", "Desarrollador", "Java"),
            new Desarrollador("Luis", "Desarrollador", "Python"),
            new Desarrollador("Ana", "Desarrollador", "JavaScript"),
            new Tester("Maria", "Tester", "Pruebas de Rendimiento"),
            new Tester("Sofia", "Tester", "Pruebas Funcionales"),
            new Tester("Lucia", "Tester", "Pruebas de Seguridad"),
            new GerenteProyecto("Carlos", "Gerente de Proyecto", "Equipo A"),
            new GerenteProyecto("Miguel", "Gerente de Proyecto", "Equipo B"),
            new GerenteProyecto("Laura", "Gerente de Proyecto", "Equipo C")
    };

    vector<Proyecto> proyectos = {
            Proyecto("Proyecto 1", "Descripción del proyecto 1", "01/09/2024", "01/12/2024"),
            Proyecto("Proyecto 2", "Descripción del proyecto 2", "01/09/2024", "01/12/2024"),
            Proyecto("Proyecto 3", "Descripción del proyecto 3", "01/09/2024", "01/12/2024"),
            Proyecto("Proyecto 4", "Descripción del proyecto 4", "01/09/2024", "01/12/2024"),
            Proyecto("Proyecto 5", "Descripción del proyecto 5", "01/09/2024", "01/12/2024")
    };

    vector<Cliente> clientes = {
            Cliente("Empresa A", "TechCorp", "info@techcorp.com"),
            Cliente("Empresa B", "SoftDev", "info@softdev.com")
    };

    vector<Tarea> tareas;

    int opcion;
    do {
        cout << "=== Menú Principal ===" << endl;
        cout << "1. Mostrar información cargada" << endl;
        cout << "2. Gestión de Proyectos" << endl;
        cout << "3. Gestión de Empleados" << endl;
        cout << "4. Gestión de Tareas" << endl;
        cout << "5. Gestión de Clientes" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "=== Información Precargada ===" << endl;

            cout << "Proyectos:" << endl;
            for (const auto& proyecto : proyectos) {
                proyecto.generarReporte();
                cout << "-----------------------------" << endl;
            }

            cout << "Empleados:" << endl;
            for (const auto& empleado : empleados) {
                cout << "Nombre: " << empleado->getNombre() << ", Puesto: " << empleado->getPuesto() << endl;
            }

            cout << "Clientes:" << endl;
            for (const auto& cliente : clientes) {
                cout << "Cliente: " << cliente.getNombre() << ", Empresa: " << cliente.getEmpresa() << endl;
            }
            cout << "=================================" << endl;

        } else if (opcion == 2) {
            int opcionProyecto;
            cout << "=== Gestión de Proyectos ===" << endl;
            cout << "1. Mostrar todos los proyectos" << endl;
            cout << "2. Agregar Proyecto" << endl;
            cout << "3. Asignar Empleados a Proyecto" << endl;
            cout << "4. Eliminar Proyecto" << endl;
            cout << "0. Volver" << endl;
            cin >> opcionProyecto;

            if (opcionProyecto == 1) {
                for (const auto& proyecto : proyectos) {
                    proyecto.generarReporte();
                    cout << "-----------------------------" << endl;
                }
            } else if (opcionProyecto == 2) {
                string nombre, descripcion, fechaInicio, fechaFin;
                cout << "Ingrese nombre del proyecto: ";
                cin >> nombre;
                cout << "Ingrese descripción: ";
                cin >> descripcion;
                cout << "Ingrese fecha de inicio: ";
                cin >> fechaInicio;
                cout << "Ingrese fecha de fin: ";
                cin >> fechaFin;
                Proyecto nuevoProyecto(nombre, descripcion, fechaInicio, fechaFin);
                proyectos.push_back(nuevoProyecto);
                cout << "Proyecto agregado." << endl;
            } else if (opcionProyecto == 3) {
                int indexProyecto;
                cout << "Ingrese el índice del proyecto: ";
                cin >> indexProyecto;
                if (indexProyecto >= 0 && indexProyecto < proyectos.size()) {
                    cout << "Asignando empleados al proyecto..." << endl;
                    for (int i = 0; i < empleados.size(); i++) {
                        cout << i << ". " << empleados[i]->getNombre() << " - " << empleados[i]->getPuesto() << endl;
                    }
                    int indexEmpleado;
                    cout << "Seleccione el índice del empleado a asignar: ";
                    cin >> indexEmpleado;
                    if (indexEmpleado >= 0 && indexEmpleado < empleados.size()) {
                        proyectos[indexProyecto].agregarEmpleado(empleados[indexEmpleado]);
                        cout << "Empleado asignado al proyecto." << endl;
                    } else {
                        cout << "Índice de empleado inválido." << endl;
                    }
                } else {
                    cout << "Índice de proyecto inválido." << endl;
                }
            } else if (opcionProyecto == 4) {
                int index;
                cout << "Ingrese el índice del proyecto a eliminar: ";
                cin >> index;
                if (index >= 0 && index < proyectos.size()) {
                    proyectos.erase(proyectos.begin() + index);
                    cout << "Proyecto eliminado." << endl;
                } else {
                    cout << "Índice inválido." << endl;
                }
            }

        } else if (opcion == 3) {
            int opcionEmpleado;
            cout << "=== Gestión de Empleados ===" << endl;
            cout << "1. Mostrar todos los empleados" << endl;
            cout << "2. Agregar Empleado" << endl;
            cout << "3. Eliminar Empleado" << endl;
            cout << "0. Volver" << endl;
            cin >> opcionEmpleado;

            if (opcionEmpleado == 1) {
                for (const auto& empleado : empleados) {
                    cout << "Nombre: " << empleado->getNombre() << ", Puesto: " << empleado->getPuesto() << endl;
                }
            } else if (opcionEmpleado == 2) {
                string nombre, puesto;
                cout << "Ingrese nombre del empleado: ";
                cin >> nombre;
                cout << "Ingrese puesto (Desarrollador/Tester/Gerente): ";
                cin >> puesto;
                if (puesto == "Desarrollador") {
                    string lenguaje;
                    cout << "Ingrese lenguaje dominado: ";
                    cin >> lenguaje;
                    empleados.push_back(new Desarrollador(nombre, puesto, lenguaje));
                } else if (puesto == "Tester") {
                    string especialidad;
                    cout << "Ingrese especialidad: ";
                    cin >> especialidad;
                    empleados.push_back(new Tester(nombre, puesto, especialidad));
                } else if (puesto == "Gerente") {
                    string equipo;
                    cout << "Ingrese equipo gestionado: ";
                    cin >> equipo;
                    empleados.push_back(new GerenteProyecto(nombre, puesto, equipo));
                } else {
                    cout << "Puesto no válido." << endl;
                }
            } else if (opcionEmpleado == 3) {
                int index;
                cout << "Ingrese el índice del empleado a eliminar: ";
                cin >> index;
                if (index >= 0 && index < empleados.size()) {
                    empleados.erase(empleados.begin() + index);
                    cout << "Empleado eliminado." << endl;
                } else {
                    cout << "Índice inválido." << endl;
                }
            }

        } else if (opcion == 4) {
            int opcionTarea;
            cout << "=== Gestión de Tareas ===" << endl;
            cout << "1. Mostrar todas las tareas" << endl;
            cout << "2. Agregar Tarea" << endl;
            cout << "3. Asignar Empleado a Tarea" << endl;
            cout << "4. Eliminar Tarea" << endl;
            cout << "0. Volver" << endl;
            cin >> opcionTarea;

            if (opcionTarea == 1) {
                for (const auto& tarea : tareas) {
                    cout << "Tarea: " << tarea.getNombre() << ", Estado: " << tarea.getEstado() << endl;
                }
            } else if (opcionTarea == 2) {
                string nombre, estado, fechaLimite;
                cout << "Ingrese nombre de la tarea: ";
                cin >> nombre;
                cout << "Ingrese estado (Pendiente/En progreso/Finalizada): ";
                cin >> estado;
                cout << "Ingrese fecha límite: ";
                cin >> fechaLimite;
                Tarea nuevaTarea(nombre, estado, fechaLimite, nullptr);
                tareas.push_back(nuevaTarea);
                cout << "Tarea agregada." << endl;
            } else if (opcionTarea == 3) {
                int indexTarea;
                cout << "Ingrese el índice de la tarea: ";
                cin >> indexTarea;
                if (indexTarea >= 0 && indexTarea < tareas.size()) {
                    cout << "Asignando empleados a la tarea..." << endl;
                    for (int i = 0; i < empleados.size(); i++) {
                        cout << i << ". " << empleados[i]->getNombre() << " - " << empleados[i]->getPuesto() << endl;
                    }
                    int indexEmpleado;
                    cout << "Seleccione el índice del empleado a asignar: ";
                    cin >> indexEmpleado;
                    if (indexEmpleado >= 0 && indexEmpleado < empleados.size()) {
                        tareas[indexTarea].setEmpleadoAsignado(empleados[indexEmpleado]);
                        cout << "Empleado asignado a la tarea." << endl;
                    } else {
                        cout << "Índice de empleado inválido." << endl;
                    }
                } else {
                    cout << "Índice de tarea inválido." << endl;
                }
            } else if (opcionTarea == 4) {
                int index;
                cout << "Ingrese el índice de la tarea a eliminar: ";
                cin >> index;
                if (index >= 0 && index < tareas.size()) {
                    tareas.erase(tareas.begin() + index);
                    cout << "Tarea eliminada." << endl;
                } else {
                    cout << "Índice inválido." << endl;
                }
            }

        } else if (opcion == 5) {
            int opcionCliente;
            cout << "=== Gestión de Clientes ===" << endl;
            cout << "1. Mostrar todos los clientes" << endl;
            cout << "2. Agregar Cliente" << endl;
            cout << "3. Eliminar Cliente" << endl;
            cout << "0. Volver" << endl;
            cin >> opcionCliente;

            if (opcionCliente == 1) {
                for (const auto& cliente : clientes) {
                    cout << "Cliente: " << cliente.getNombre() << ", Empresa: " << cliente.getEmpresa() << endl;
                }
            } else if (opcionCliente == 2) {
                string nombre, empresa, contacto;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese empresa: ";
                cin >> empresa;
                cout << "Ingrese contacto: ";
                cin >> contacto;
                Cliente nuevoCliente(nombre, empresa, contacto);
                clientes.push_back(nuevoCliente);
                cout << "Cliente agregado." << endl;
            } else if (opcionCliente == 3) {
                int index;
                cout << "Ingrese el índice del cliente a eliminar: ";
                cin >> index;
                if (index >= 0 && index < clientes.size()) {
                    clientes.erase(clientes.begin() + index);
                    cout << "Cliente eliminado." << endl;
                } else {
                    cout << "Índice inválido." << endl;
                }
            }
        } else if (opcion != 0) {
            cout << "Opción no válida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
