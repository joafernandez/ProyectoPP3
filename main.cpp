#include <iostream>
#include <vector>
#include "Empleado.h"
#include "Desarrollador.h"
#include "Tester.h"
#include "GerenteProyecto.h"
#include "Proyecto.h"
#include "Tarea.h"
#include "Cliente.h"
#include <algorithm>"

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
            new GerenteProyecto("Laura", "Gerente de Proyecto", "Equipo C"),
    };

    vector<Proyecto> proyectos = {
            Proyecto("Portal de Ventas Online", "Desarrollo de un portal de ventas para productos electrónicos", "01/09/2024", "03/12/2024"),
            Proyecto("App de Pedidos de Comida", "Desarrollo de una aplicación móvil para pedidos de comida a domicilio", "03/09/2024", "01/12/2024"),
            Proyecto("Sistema de Gestion de Inventarios", "Sistema para gestionar inventarios de una cadena de tiendas", "07/09/2024", "06/12/2024"),
            Proyecto("Automatización de Facturación", "Proyecto para automatizar el proceso de facturación de la empresa", "08/09/2024", "02/12/2024"),
            Proyecto("Sistema de Soporte Técnico", "Desarrollo de una plataforma para gestionar solicitudes de soporte técnico", "10/09/2024", "04/12/2024"),
            Proyecto("Integración de API de Pagos", "Integración de una nueva API de pagos para la plataforma de ventas", "14/09/2024", "02/12/2024"),
            Proyecto("Aplicación de Chat para Atención al Cliente", "Desarrollo de una aplicación de chat en tiempo real para atención al cliente", "18/09/2024", "06/12/2024"),
    };

    vector<Cliente> clientes = {
            Cliente("Farmacity", "Farmacity", "contacto@farmacity.com"),
            Cliente("AnibalTuc", "AnibalTuc", "info@anibaltuc.com"),
            Cliente("FerTec", "FerTec", "contacto@fertec.com"),
            Cliente("TurboTejada", "TurboTejada", "contacto@turbotejada.com"),
            Cliente("DAS", "DAS", "info@das.com"),
            Cliente("Digital Solutions", "Digital Solutions", "contacto@digitalsolutions.com"),
            Cliente("TecnoFe", "TecnoFe", "soporte@tecnofe.com"),
    };

    vector<Tarea> tareas={
            Tarea("Diseniar interfaz de usuario", "en progreso", "20/10/2024", empleados[1]), // Pedro
            Tarea("Pruebas de carga en el servidor", "pendiente", "25/10/2024", empleados[4]), // Maria

    };

    int opcion;
    do {
        cout << "======================================== GESTION DE OPCIONES ==========================================" << endl;
        cout << "1. Mostrar informacion cargada" << endl;
        cout << "2. Gestion de Proyectos" << endl;
        cout << "3. Gestion de Empleados" << endl;
        cout << "4. Gestion de Tareas" << endl;
        cout << "5. Gestion de Clientes" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "=== Informacion Precargada ===" << endl;

            cout << "Proyectos:" << endl;
            for (const auto &proyecto : proyectos) {
                cout << "Proyecto: " << proyecto.getNombre() << endl;


                // Mostrar empleados del proyecto usando iteradores
                cout << "Empleados asignados:" << endl;
                for (auto it = proyecto.beginEmpleados(); it != proyecto.endEmpleados(); ++it) {
                    cout << "Empleado: " << (*it)->getNombre() << ", Puesto: " << (*it)->getPuesto() << endl;
                }

                // Mostrar tareas del proyecto usando iteradores
                cout << "Tareas del proyecto:" << endl;
                for (auto it = proyecto.beginTareas(); it != proyecto.endTareas(); ++it) {
                    cout << "Tarea: " << (*it)->getNombre() << ", Estado: " << (*it)->getEstado()
                         << ", Fecha Límite: " << (*it)->getFechaLimite() << endl;
                }

                cout << "-----------------------------" << endl;
            }

            cout << "Empleados:" << endl;
            for (const auto &empleado : empleados) {
                cout << "Nombre: " << empleado->getNombre() << ", Puesto: " << empleado->getPuesto() << endl;
            }

            cout << "Clientes:" << endl;
            for (const auto &cliente : clientes) {
                cout << "Cliente: " << cliente.getNombre() << ", Empresa: " << cliente.getEmpresa() << endl;
            }
            cout << "=================================" << endl;

        } else if (opcion == 2) {
            int opcionProyecto;
            do {
                cout << "======================================== GESTION DE PROYECTOS =======================================" << endl;
                cout << "1. Mostrar todos los proyectos" << endl;
                cout << "2. Agregar Proyecto" << endl;
                cout << "3. Asignar Empleados a Proyecto" << endl;
                cout << "4. Eliminar Proyecto" << endl;
                cout << "5. Ordenar proyectos por fecha de finalización" << endl; // Nueva opción
                cout << "0. Volver" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionProyecto;
                cin.ignore(); // Limpiar el buffer de entrada

                if (opcionProyecto == 1) {
                    // Mostrar todos los proyectos con sus índices
                    cout << "=== Lista de Proyectos ===" << endl;
                    for (int i = 0; i < proyectos.size(); ++i) {
                        cout << "INDICE: " << i << " - Proyecto: " << proyectos[i].getNombre() << endl;
                    }
                    cout << "=========================" << endl;

                } else if (opcionProyecto == 2) {
                    // Agregar nuevo proyecto
                    string nombre, descripcion, fechaInicio, fechaFin;
                    cout << "Ingrese nombre del proyecto: ";
                    cin.ignore(); // Limpiar el buffer antes de leer cadenas
                    getline(cin, nombre);
                    cout << "Ingrese descripción: ";
                    getline(cin, descripcion);
                    cout << "Ingrese fecha de inicio: ";
                    getline(cin, fechaInicio);
                    cout << "Ingrese fecha de fin: ";
                    getline(cin, fechaFin);
                    Proyecto nuevoProyecto(nombre, descripcion, fechaInicio, fechaFin);
                    proyectos.push_back(nuevoProyecto);
                    cout << "Proyecto agregado." << endl;

                } else if (opcionProyecto == 3) {
                    // Asignar empleados a un proyecto
                    int indexProyecto;
                    cout << "Ingrese el índice del proyecto: ";
                    cin >> indexProyecto;
                    // Verificar y asignar empleados...
                } else if (opcionProyecto == 4) {
                    // Eliminar proyecto
                    int index;
                    cout << "Ingrese el indice del proyecto a eliminar: ";
                    cin >> index;
                    if (index >= 0 && index < proyectos.size()) {
                        proyectos.erase(proyectos.begin() + index);
                        cout << "Proyecto eliminado." << endl;
                    } else {
                        cout << "Indice de proyecto invalido." << endl;
                    }
                } else if (opcionProyecto == 5) {
                    // Nueva opción: Ordenar proyectos por fecha de finalización
                    sort(proyectos.begin(), proyectos.end()); // Usa la sobrecarga del operador <
                    cout << "Proyectos ordenados por fecha de finalización:" << endl;
                    for (const auto &proyecto : proyectos) {
                        proyecto.generarReporte();
                        cout << "-----------------------------" << endl;
                    }
                } else if (opcionProyecto != 0) {
                    cout << "Opcion no válida." << endl;
                }
            } while (opcionProyecto != 0); // Mantiene el bucle hasta que el usuario ingrese 0 para salir
        }

            else if (opcion == 3) {
            int opcionEmpleado;
            do {
                cout << "======================================== GESTION DE EMPLEADOS =======================================" << endl;
                cout
                        << "1. Mostrar todos los empleados \t 2. Agregar Empleado\t 3. Eliminar Empleado \t 0. Volver a Menu Principal"
                        << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionEmpleado;
                cin.ignore(); // Limpiar el buffer de entrada


                 if (opcionEmpleado == 1) {
                    cout << "=== Lista de Empleados ===" << endl;
                    for (size_t i = 0; i < empleados.size(); ++i) {
                        cout << "INDICE: " << i << " - Nombre: " << empleados[i]->getNombre()
                             << ", Puesto: " << empleados[i]->getPuesto() << endl;
                    }
                    cout << "=========================" << endl;




                } else if (opcionEmpleado == 2) {
                    string nombre, puesto;
                    cout << "Ingrese nombre del empleado: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese puesto (Desarrollador/Tester/Gerente): ";
                    getline(cin, puesto);
                    if (puesto == "Desarrollador") {
                        string lenguaje;
                        cout << "Ingrese lenguaje dominado: ";
                        getline(cin, lenguaje);
                        empleados.push_back(new Desarrollador(nombre, puesto, lenguaje));
                        cout << "Desarrollador agregado." << endl;
                    } else if (puesto == "Tester") {
                        string especialidad;
                        cout << "Ingrese especialidad: ";
                        getline(cin, especialidad);
                        empleados.push_back(new Tester(nombre, puesto, especialidad));
                        cout << "Tester agregado." << endl;
                    } else if (puesto == "Gerente") {
                        string equipo;
                        cout << "Ingrese equipo gestionado: ";
                        getline(cin, equipo);
                        empleados.push_back(new GerenteProyecto(nombre, puesto, equipo));
                        cout << "Gerente de Proyecto agregado." << endl;
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
                } else if (opcionEmpleado != 0) {
                    cout << "Opción no válida." << endl;
                }
            } while (opcionEmpleado != 0); // Mantiene el bucle hasta que el usuario ingrese 0 para salir
        }
            else if (opcion == 4) {
            int opcionTarea;
            do {
                cout << "======================================== GESTION DE TAREAS ==========================================" << endl;
                cout
                        << "1) Mostrar todas las tareas\t2) Agregar Tarea\t3) Asignar Empleado a Tarea\t4) Eliminar Tarea\t\n 5) Ordenar por Fecha Limite   0) Volver al Menu Principal"
                        << endl;
                cout << "INGRESE SU OPCION: ";
                cin >> opcionTarea;
                cin.ignore(); // Limpiar el buffer de entrada

                if (opcionTarea == 1) {
                    // Mostrar todas las tareas
                    if (tareas.empty()) {
                        cout << "No hay tareas cargadas." << endl;
                    } else {
                        for (int i = 0; i < tareas.size(); ++i) {
                            cout << "Indice: " << i << " - Tarea: " << tareas[i].getNombre()
                                 << ", Estado: " << tareas[i].getEstado()
                                 << ", Fecha Limite: " << tareas[i].getFechaLimite() << endl;

                            if (tareas[i].getEmpleadoAsignado() != nullptr) {
                                cout << "Empleado Asignado: " << tareas[i].getEmpleadoAsignado()->getNombre()
                                     << endl;
                            } else {
                                cout << "Empleado Asignado: Ninguno" << endl;
                            }
                            cout << "-----------------------------" << endl;
                        }
                    }
                } else if (opcionTarea == 2) {
                    // Agregar Tarea
                    string nombre, estado, fechaLimite;
                    cout << "Ingrese nombre de la tarea: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese estado (Pendiente/En progreso/Finalizada): ";
                    getline(cin, estado);
                    cout << "Ingrese fecha límite: ";
                    getline(cin, fechaLimite);
                    Tarea nuevaTarea(nombre, estado, fechaLimite, nullptr);
                    tareas.push_back(nuevaTarea);
                    cout << "Tarea agregada." << endl;
                } else if (opcionTarea == 3) {
                    // Asignar Empleado a Tarea
                    if (tareas.empty()) {
                        cout << "No hay tareas disponibles para asignar empleados." << endl;
                    } else {
                        int indexTarea;
                        cout << "Ingrese el índice de la tarea: ";
                        cin >> indexTarea;

                        if (indexTarea >= 0 && indexTarea < tareas.size()) {
                            cout << "Asignando empleados a la tarea..." << endl;

                            for (int i = 0; i < empleados.size(); i++) {
                                cout << i << ". " << empleados[i]->getNombre() << " - " << empleados[i]->getPuesto()
                                     << endl;
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
                    }
                } else if (opcionTarea == 4) {
                    // Eliminar Tarea
                    if (tareas.empty()) {
                        cout << "No hay tareas para eliminar." << endl;
                    } else {
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
                }//ACA PRUEBO OPCION 5
            else if (opcionTarea == 5) {
                // Ordenar tareas por fecha límite
                if (tareas.empty()) {
                    cout << "No hay tareas para ordenar." << endl;
                } else {
                    sort(tareas.begin(), tareas.end()); // Esto ahora usa la sobrecarga del operador <
                    cout << "Tareas ordenadas por fecha límite:" << endl;
                    for (const auto& tarea : tareas) {
                        cout << "Tarea: " << tarea.getNombre()
                             << ", Fecha Límite: " << tarea.getFechaLimite()
                             << ", Estado: " << tarea.getEstado() << endl;
                    }
                }
            }
            else if (opcionTarea != 0) {
                    cout << "Opción no válida." << endl;
                }
            } while (opcionTarea != 0); // Mantiene el bucle hasta que el usuario ingrese 0 para salir

        } //esta funcionaba bien cuando imprimi




        else if (opcion == 5) {
            int opcionCliente;
            do {
                cout << "                           === Gestion de Clientes ===" << endl;
                cout << "1. Mostrar todos los clientes\t2. Agregar Cliente\t3. Eliminar Cliente\t0. Volver" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionCliente;
                cin.ignore(); // Limpiar el buffer de entrada

                if (opcionCliente == 1) {
                    if (clientes.empty()) {
                        cout << "No hay clientes cargados." << endl;
                    } else {
                        for (int i = 0; i < clientes.size(); ++i) {
                            cout << "Indice: " << i << " - Cliente: " << clientes[i].getNombre()
                                 << ", Empresa: " << clientes[i].getEmpresa() << endl;
                        }
                    }
                } else if (opcionCliente == 2) {
                    // Agregar Cliente
                    string nombre, empresa, contacto;
                    cout << "Ingrese nombre del cliente: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese empresa: ";
                    getline(cin, empresa);
                    cout << "Ingrese contacto: ";
                    getline(cin, contacto);
                    Cliente nuevoCliente(nombre, empresa, contacto);
                    clientes.push_back(nuevoCliente);
                    cout << "Cliente agregado." << endl;
                } else if (opcionCliente == 3) {
                    // Eliminar Cliente
                    if (clientes.empty()) {
                        cout << "No hay clientes para eliminar." << endl;
                    } else {
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
                } else if (opcionCliente != 0) {
                    cout << "Opcion no válida." << endl;
                }
            } while (opcionCliente != 0); // Mantiene el bucle hasta que el usuario ingrese 0 para salir
        }
            else if(opcion != 0) {
            cout << "Opción no válida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
