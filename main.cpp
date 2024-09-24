

#include <iostream>
#include "Empleado.h"
#include "Desarrollador.h"
#include "Tester.h"
#include "GerenteProyecto.h"
#include "Tarea.h"
#include "Proyecto.h"
#include "Cliente.h"
#include "ReunionSeguimiento.h"
#include "Reporte .h"

int main() {
    // Crear empleados
    Desarrollador dev1("Juan", "Desarrollador", "C++");
    Tester tester1("Maria", "Tester", "Pruebas Funcionales");
    GerenteProyecto gerente1("Carlos", "Gerente de Proyecto", "Equipo de Desarrollo A");

    // Asignar proyectos
    dev1.asignarProyecto();
    tester1.asignarProyecto();
    gerente1.asignarProyecto();

    // Crear un proyecto
    Proyecto proyecto1("Proyecto Software", "Desarrollo de una aplicación web", "01/09/2024", "01/12/2024");

    // Agregar empleados al proyecto
    proyecto1.agregarEmpleado(&dev1);
    proyecto1.agregarEmpleado(&tester1);
    proyecto1.agregarEmpleado(&gerente1);

    // Crear tareas y asignarlas
    Tarea tarea1("Desarrollar el módulo de autenticación", "Pendiente", "15/10/2024", &dev1);
    Tarea tarea2("Realizar pruebas de carga", "Pendiente", "20/10/2024", &tester1);

    proyecto1.agregarTarea(&tarea1);
    proyecto1.agregarTarea(&tarea2);

    // Actualizar estado de una tarea
    tarea1.actualizarEstado("En progreso");
    tarea2.actualizarEstado("Finalizada");

    // Finalizar tarea por parte de los empleados
    dev1.finalizarTarea();
    tester1.finalizarTarea();

    // Crear un cliente
    Cliente cliente1("Empresa X", "TechCorp", "contacto@techcorp.com");

    // El cliente solicita un reporte
    cliente1.solicitarReporte();

    // Crear reuniones de seguimiento
    ReunionSeguimiento reunion1("10/10/2024", "10:00 AM");
    reunion1.agendarReunion({"Juan", "Maria", "Carlos"}, {"Avance del proyecto", "Revisar tareas completadas"});
    reunion1.generarResumen();

    // Crear un reporte de progreso
    Reporte reporte1("Avance del 60% completado");
    reporte1.agregarTareaCompletada("Desarrollar el módulo de autenticación");
    reporte1.agregarResumenReunion(reunion1);

    // Generar reporte final del proyecto
    proyecto1.generarReporte();
    reporte1.generarReporteProgreso();

    return 0;
}
