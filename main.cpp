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
#include <sstream>
#include <algorithm>

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
            Proyecto("Portal de Ventas Online", "Desarrollo de un portal de ventas para productos electronicos", "01/09/2024", "03/12/2024"),
            Proyecto("App de Pedidos de Comida", "Desarrollo de una aplicacion movil para pedidos de comida a domicilio", "03/09/2024", "01/12/2024"),
            Proyecto("Sistema de Gestion de Inventarios", "Sistema para gestionar inventarios de una cadena de tiendas", "07/09/2024", "06/12/2024"),
            Proyecto("Automatizacion de Facturacion", "Proyecto para automatizar el proceso de facturacion de la empresa", "08/09/2024", "02/12/2024"),
            Proyecto("Sistema de Soporte Tecnico", "Desarrollo de una plataforma para gestionar solicitudes de soporte tecnico", "10/09/2024", "04/12/2024"),
            Proyecto("Integracion de API de Pagos", "Integracion de una nueva API de pagos para la plataforma de ventas", "14/09/2024", "02/12/2024"),
            Proyecto("Aplicacion de Chat para Atencion al Cliente", "Desarrollo de una aplicacion de chat en tiempo real para atencion al cliente", "18/09/2024", "06/12/2024"),
    };

    vector<Cliente> clientes = {
            Cliente("Farmacity", "Farmacity", "contacto@gmail.com"),
            Cliente("AnibalTuc", "AnibalTuc", "info@gmail.com"),
            Cliente("FerTec", "FerTec", "fercto@gmail.com"),
            Cliente("TurboTejada", "TurboTejada", "contacto@turbotejada.com"),
            Cliente("DAS", "DAS", "info@das.com"),
            Cliente("Digital Solutions", "Digital Solutions", "digitalsolutions@gamil.com"),
            Cliente("TecnoFe", "TecnoFe", "soporte@tecnofe.com"),
    };

    vector<Tarea> tareas={
            Tarea("Diseniar interfaz de usuario", "en progreso", "20/10/2024", empleados[1]), // Pedro
            Tarea("Pruebas de carga en el servidor", "pendiente", "25/10/2024", empleados[4]), // Maria

    };

    vector<ReunionSeguimiento> reuniones;


    int opcion;
    do {
        cout << "======================================== MENU DE OPCIONES ==========================================" << endl;
        cout << "1. Mostrar informacion cargada" << endl;
        cout << "2. Gestion de Proyectos" << endl;
        cout << "3. Gestion de Empleados" << endl;
        cout << "4. Gestion de Tareas" << endl;
        cout << "5. Gestion de Clientes" << endl;
        cout << "6. Agendar Reunion de Seguimiento" << endl;
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

        }



        else if (opcion == 2) {
            int opcionProyecto;
            do {
                cout << "======================================== GESTION DE PROYECTOS =======================================" << endl;
                cout << "1. Mostrar todos los proyectos" << endl;
                cout << "2. Agregar Proyecto" << endl;
                cout << "3. Asignar Empleados a Proyecto" << endl;
                cout << "4. Eliminar Proyecto" << endl;
                cout << "5. Ordenar proyectos por fecha de finalizacion" << endl; // Nueva opción
                cout << "0. Volver a menu principal" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionProyecto;
                cin.ignore(); // Limpiar el buffer de entrada

                if (opcionProyecto == 1) {
                    // Mostrar todos los proyectos con sus indices
                    cout << " =========================================== LISTA DE PROYECTOS ==========================================" << endl;
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
                    cout << "Ingrese descripcion: ";
                    getline(cin, descripcion);
                    cout << "Ingrese fecha de inicio: ";
                    getline(cin, fechaInicio);
                    cout << "Ingrese fecha de fin: ";
                    getline(cin, fechaFin);
                    Proyecto nuevoProyecto(nombre, descripcion, fechaInicio, fechaFin);
                    proyectos.push_back(nuevoProyecto);
                    cout << "        Proyecto agregado :)  " << endl;

                } else if (opcionProyecto == 3) {
                    // Asignar empleados a un proyecto
                    int indexProyecto;
                    cout << "Ingrese el Indice del proyecto: ";
                    cin >> indexProyecto;

                    // Verificamos que el índice del proyecto sea válido
                    if (indexProyecto >= 0 && indexProyecto < proyectos.size()) {
                        // Mostramos los empleados disponibles
                        cout << "============================ Lista de Empleados Disponibles ==========================" << endl;
                        for (int i = 0; i < empleados.size(); ++i) {
                            cout << "INDICE: " << i << " - Empleado: " << empleados[i]->getNombre() << endl;
                        }

                        // Seleccionamos el empleado para asignar al proyecto
                        int indexEmpleado;
                        cout << "Ingrese el indice del empleado a asignar: ";
                        cin >> indexEmpleado;

                        // Verificamos que el índice del empleado sea válido
                        if (indexEmpleado >= 0 && indexEmpleado < empleados.size()) {
                            // Utilizamos la función agregarEmpleado de la clase Proyecto
                            proyectos[indexProyecto].agregarEmpleado(empleados[indexEmpleado]);
                            cout << "Empleado asignado correctamente al proyecto: "
                                 << proyectos[indexProyecto].getNombre() << endl;
                        } else {
                            cout << "Índice de empleado inválido." << endl;
                        }
                    } else {
                        cout << "indice de proyecto invalido." << endl;
                    }


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
                    cout << "Proyectos ordenados por fecha de finalizacion:" << endl;
                    for (const auto &proyecto : proyectos) {
                        proyecto.generarReporte();
                        cout << "-----------------------------" << endl;
                    }
                } else if (opcionProyecto != 0) {
                    cout << "Opcion no valida." << endl;
                }
            } while (opcionProyecto != 0); // Mantiene el bucle hasta que el usuario ingrese 0 para salir
        }

        else if (opcion == 3) {
            int opcionEmpleado;
            do {
                cout << "======================================== GESTION DE EMPLEADOS =======================================" << endl;
                cout
                        << "1. Mostrar todos los empleados "<<endl;
                cout<<"2. Agregar Empleado" <<endl;
                cout<<"3. Eliminar Empleado"<<endl;
                cout<<"0. Volver a Menu Principal"<<endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionEmpleado;
                cin.ignore(); // Limpiar el buffer de entrada


                 if (opcionEmpleado == 1) {
                    cout << "======================================= Lista de Empleados ==========================================" << endl;
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
                    cout << "Ingrese el indice del empleado a eliminar: ";
                    cin >> index;
                    if (index >= 0 && index < empleados.size()) {
                        empleados.erase(empleados.begin() + index);
                        cout << "Empleado eliminado." << endl;
                    } else {
                        cout << "Indice invalido." << endl;
                    }
                } else if (opcionEmpleado != 0) {
                    cout << "Opcion no valida." << endl;
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
                    cout << "Ingrese fecha limite: ";
                    getline(cin, fechaLimite);
                    Tarea nuevaTarea(nombre, estado, fechaLimite, nullptr);
                    tareas.push_back(nuevaTarea);
                    cout << "Tarea agregada :)  " << endl;
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
                            cout << "Seleccione el indice del empleado a asignar: ";
                            cin >> indexEmpleado;

                            if (indexEmpleado >= 0 && indexEmpleado < empleados.size()) {
                                tareas[indexTarea].setEmpleadoAsignado(empleados[indexEmpleado]);
                                cout << "Empleado asignado a la tarea." << endl;
                            } else {
                                cout << "Indice de empleado invalido." << endl;
                            }
                        } else {
                            cout << "Indice de tarea invalido." << endl;
                        }
                    }
                } else if (opcionTarea == 4) {
                    // Eliminar Tarea
                    if (tareas.empty()) {
                        cout << "No hay tareas para eliminar." << endl;
                    } else {
                        int index;
                        cout << "Ingrese el indice de la tarea a eliminar: ";
                        cin >> index;
                        if (index >= 0 && index < tareas.size()) {
                            tareas.erase(tareas.begin() + index);
                            cout << "Tarea eliminada." << endl;
                        } else {
                            cout << "Indice invalido." << endl;
                        }
                    }
                }//ACA PRUEBO OPCION 5
            else if (opcionTarea == 5) {
                // Ordenar tareas por fecha límite
                if (tareas.empty()) {
                    cout << "No hay tareas para ordenar." << endl;
                } else {
                    sort(tareas.begin(), tareas.end()); // Esto ahora usa la sobrecarga del operador <
                    cout << "Tareas ordenadas por fecha limite:" << endl;
                    for (const auto& tarea : tareas) {
                        cout << "Tarea: " << tarea.getNombre()
                             << ", Fecha Limite: " << tarea.getFechaLimite()
                             << ", Estado: " << tarea.getEstado() << endl;
                    }
                }
            }

            else if (opcionTarea != 0) {
                    cout << "Opcion no valida." << endl;
                }
            } while (opcionTarea != 0); // Mantiene el bucle hasta que el usuario ingrese 0 para salir

        } //esta funcionaba bien cuando imprimi

        else if (opcion == 5) {

            int opcionCliente;
            do {
                cout << "======================================== GESTION DE CLIENTES ==========================================" << endl;
                cout << "1. Mostrar todos los clientes\t2. Agregar Cliente\t3. Eliminar Cliente\t4. Solicitar Reporte de Cliente\t0. Volver" << endl;
                cout << "Ingrese su opcion: ";
                cin >> opcionCliente;
                cin.ignore(); // Limpiar el buffer de entrada

                switch (opcionCliente) {
                    case 1:
                        void mostrarClientes(const vector<Cliente>& clientes); {
                        if (clientes.empty()) {
                            cout << "No hay clientes cargados." << endl;
                        } else {
                            for (int i = 0; i < clientes.size(); ++i) {
                                cout << "Indice: " << i << " - Cliente: " << clientes[i].getNombre()
                                     << ", Empresa: " << clientes[i].getEmpresa() << endl;
                            }
                        }
                    }
                        break;
                    case 2:
                        void agregarCliente(vector<Cliente>& clientes); {
                        string nombre, empresa, contacto;
                        cout << "Ingrese nombre del cliente: ";
                        getline(cin, nombre);
                        cout << "Ingrese empresa: ";
                        getline(cin, empresa);
                        cout << "Ingrese contacto: ";
                        getline(cin, contacto);

                        // Validar entrada
                        if (nombre.empty() || empresa.empty()) {
                            cout << "Nombre y empresa no pueden estar vacios." << endl;
                        }

                        Cliente nuevoCliente(nombre, empresa, contacto);
                        clientes.push_back(nuevoCliente);
                        cout << "Cliente agregado." << endl;
                    }
                        break;
                    case 3:
                            void eliminarCliente(vector<Cliente>& clientes); {
                                if (clientes.empty()) {
                                    cout << "No hay clientes para eliminar." << endl;
                                } else {
                                    int indice;
                                    cout << "Ingrese el indice del cliente a eliminar: ";
                                    cin >> indice;
                                    if (indice >= 0 && indice < clientes.size()) {
                                        cout << "¿Está seguro de eliminar al cliente? (s/n)?";
                                        char respuesta;
                                        cin >> respuesta;
                                        if (respuesta == 's') {
                                            clientes.erase(clientes.begin() + indice);
                                            cout << "Cliente eliminado." << endl;
                                        }
                                    } else {
                                        cout << "Indice invalido." << endl;
                                    }
                                }
                            }
                        break;
                    case 4:
                        void solicitarReporteCliente(vector<Cliente>& clientes); {
                            if (clientes.empty()) {
                                cout << "No hay clientes para solicitar reporte." << endl;
                            } else {
                                int indice;
                                cout << "Ingrese el indice del cliente que solicitara reporte: ";
                                cin >> indice;
                                if (indice >= 0 && indice < clientes.size()) {
                                    clientes[indice].solicitarReporte();
                                } else {
                                    cout << "Indice invalido." << endl;
                                }
                            }
                        }
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion no valida." << endl;
                }
            } while (opcionCliente != 0);

    }

        else if (opcion == 6) {
        do {
            cout << "====================================== GESTION DE REUNIONES =========================================" << endl;
            cout << "1. Mostrar reuniones agendadas\t2. Agregar reunion\t3. Eliminar reunion\t0. Volver" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            cin.ignore(); // Limpiar el buffer de entrada

            if (opcion == 1) {
                // Mostrar reuniones agendadas
                cout << "Reuniones agendadas:" << endl;
                for (int i = 0; i < reuniones.size(); ++i) {
                    cout << "INDICE: " << i << endl;
                    cout << "Fecha: " << reuniones[i].getFecha() << endl;
                    cout << "Hora: " << reuniones[i].getHora() << endl;
                    cout << "Asistentes: ";
                    for (const auto &asistente : reuniones[i].getListaAsistentes()) {
                        cout << asistente << ", ";
                    }
                    cout << endl;cout << "Temas: ";
                        for (size_t j = 0; j < reuniones[i].getTemasDiscutidos().size(); ++j) {
                            cout << reuniones[i].getTemasDiscutidos()[j];
                            if (j < reuniones[i].getTemasDiscutidos().size() - 1) {
                                cout << ", "; // Solo agregar la coma si no es el último tema
                            }
                        }
                        cout << endl;

                    cout << "-----------------------------" << endl;
                }

            } else if (opcion == 2) {
                // Agregar nueva reunion
                string fecha, hora;
                cout << "Ingrese fecha de la reunion: ";
                getline(cin, fecha);
                cout << "Ingrese hora de la reunion: ";
                getline(cin, hora);

                vector<string> asistentes;
                string asistente;
                cout << "Ingrese los asistentes (separados por coma): ";
                getline(cin, asistente);
                stringstream ss(asistente);
                while (ss >> asistente) {
                    asistentes.push_back(asistente);
                }

                vector<string> temas;
                string tema;
                cout << "Ingrese los temas (separados por coma): ";
                getline(cin, tema);

                // Dividir la cadena por comas
                size_t pos = 0;
                string item;
                while ((pos = tema.find(',')) != string::npos) {
                    item = tema.substr(0, pos);
                    item.erase(0, item.find_first_not_of(" "));
                    item.erase(item.find_last_not_of(" ") + 1);
                    temas.push_back(item);
                    tema.erase(0, pos + 1);
                }

                // Agregar el último tema (después de la última coma)
                tema.erase(0, tema.find_first_not_of(" "));
                tema.erase(tema.find_last_not_of(" ") + 1);
                if (!tema.empty()) {
                    temas.push_back(tema);
                }

                ReunionSeguimiento reunion(fecha, hora);
                reunion.agendarReunion(asistentes, temas);
                reuniones.push_back(reunion);
                cout << "Reunion agendada." << endl;

            } else if (opcion == 3) {
                // Eliminar reunion
                int indice;
                cout << "Ingrese el indice de la reunion a eliminar: ";
                cin >> indice;
                cin.ignore();
                if (indice >= 0 && indice < reuniones.size()) {
                    reuniones.erase(reuniones.begin() + indice);
                    cout << "Reunion eliminada." << endl;
                } else {
                    cout << "Indice de reunion invalido." << endl;
                }

            } else if (opcion != 0) {
                cout << "Opcion no valida." << endl;
            }
        } while (opcion != 0);
    }

        else if(opcion != 0) {
        cout << "Opcion no valida." << endl;
    }

    } while (opcion != 0);

    return 0;
}
