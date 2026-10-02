#include <iostream>
#include <string>

using namespace std;

const int MAX = 10;

class Materia {
private:
    string nombre;
    string clave;

public:
    Materia() {
        nombre = "";
        clave = "";
    }

    void setNombre(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }

    void setClave(string c) {
        clave = c;
    }

    string getClave() {
        return clave;
    }

    void mostrar() {
        cout << "Materia: " << nombre << endl;
        cout << "Clave: " << clave << endl;
    }
};

class Calificacion {
private:
    string claveMateria;
    float nota;

public:
    Calificacion() {
        claveMateria = "";
        nota = 0.0;
    }

    void setClaveMateria(string c) {
        claveMateria = c;
    }

    string getClaveMateria() {
        return claveMateria;
    }

    void setNota(float n) {
        if (n >= 0 && n <= 10) {
            nota = n;
        } else {
            cout << "Nota invalida." << endl;
        }
    }

    float getNota() {
        return nota;
    }

    void mostrar() {
        cout << "Clave Materia: " << claveMateria << endl;
        cout << "Nota: " << nota << endl;
    }
};

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona() {
        nombre = "";
        edad = 0;
    }

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void setNombre(string n) {
        nombre = n;
    }

    string getNombre() {
        return nombre;
    }

    void setEdad(int e) {
        if (e >= 0) {
            edad = e;
        } else {
            cout << "Edad invalida." << endl;
        }
    }

    int getEdad() {
        return edad;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }

    virtual ~Persona() {
    }
};

class Alumno : public Persona {
private:
    string matricula;
    Materia materias[10];
    Calificacion calificaciones[10];
    int numMaterias;
    int numCalificaciones;

public:
    Alumno() : Persona() {
        matricula = "";
        numMaterias = 0;
        numCalificaciones = 0;
    }

    Alumno(string n, int e, string m) : Persona(n, e) {
        matricula = m;
        numMaterias = 0;
        numCalificaciones = 0;
    }

    void setMatricula(string m) {
        matricula = m;
    }

    string getMatricula() {
        return matricula;
    }

    int getNumMaterias() {
        return numMaterias;
    }

    int getNumCalificaciones() {
        return numCalificaciones;
    }

    void agregarMateria(Materia m) {
        if (numMaterias < 10) {
            materias[numMaterias] = m;
            numMaterias++;
        } else {
            cout << "No hay espacio para mas materias." << endl;
        }
    }

    Materia getMateria(int i) {
        return materias[i];
    }

    void registrarCalificacion(Calificacion c) {
        if (numCalificaciones < 10) {
            calificaciones[numCalificaciones] = c;
            numCalificaciones++;
        } else {
            cout << "No hay espacio para mas calificaciones." << endl;
        }
    }

    Calificacion getCalificacion(int i) {
        return calificaciones[i];
    }

    int buscarMateria(string clave) {
        for (int i = 0; i < numMaterias; i++) {
            if (materias[i].getClave() == clave) {
                return i;
            }
        }
        return -1;
    }

    void mostrar() {
        Persona::mostrar();
        cout << "Matricula: " << matricula << endl;
    }
};

class Maestro : public Persona {
private:
    string especialidad;

public:
    Maestro() : Persona() {
        especialidad = "";
    }

    Maestro(string n, int e, string esp) : Persona(n, e) {
        especialidad = esp;
    }

    void setEspecialidad(string esp) {
        especialidad = esp;
    }

    string getEspecialidad() {
        return especialidad;
    }

    void mostrar() {
        Persona::mostrar();
        cout << "Especialidad: " << especialidad << endl;
    }
};

class Administrador : public Persona {
private:
    string departamento;

public:
    Administrador() : Persona() {
        departamento = "";
    }

    Administrador(string n, int e, string d) : Persona(n, e) {
        departamento = d;
    }

    void setDepartamento(string d) {
        departamento = d;
    }

    string getDepartamento() {
        return departamento;
    }

    void mostrar() {
        Persona::mostrar();
        cout << "Departamento: " << departamento << endl;
    }
};

Persona* personas[100];
int numPersonas = 0;

Alumno alumnos[MAX];
int cantidadAlumnos = 0;

int buscarIndiceAlumno(string nombre) {
    for (int i = 0; i < cantidadAlumnos; i++) {
        if (alumnos[i].getNombre() == nombre) {
            return i;
        }
    }
    return -1;
}

void registrarAlumno() {
    if (cantidadAlumnos >= MAX) {
        cout << "No hay espacio para mas alumnos." << endl;
        return;
    }
    string n;
    int e;
    string m;

    cout << "Nombre: ";
    cin >> n;
    cout << "Edad: ";
    cin >> e;
    cout << "Matricula: ";
    cin >> m;

    alumnos[cantidadAlumnos].setNombre(n);
    alumnos[cantidadAlumnos].setEdad(e);
    alumnos[cantidadAlumnos].setMatricula(m);

    cantidadAlumnos++;
    cout << "Alumno registrado." << endl;
}

void registrarMaestro() {
    if (numPersonas >= 100) {
        cout << "No hay espacio." << endl;
        return;
    }
    string n;
    int e;
    string esp;

    cout << "Nombre: ";
    cin >> n;
    cout << "Edad: ";
    cin >> e;
    cout << "Especialidad: ";
    cin >> esp;

    personas[numPersonas] = new Maestro(n, e, esp);
    numPersonas++;
    cout << "Maestro registrado." << endl;
}

void registrarAdministrador() {
    if (numPersonas >= 100) {
        cout << "No hay espacio." << endl;
        return;
    }
    string n;
    int e;
    string d;

    cout << "Nombre: ";
    cin >> n;
    cout << "Edad: ";
    cin >> e;
    cout << "Departamento: ";
    cin >> d;

    personas[numPersonas] = new Administrador(n, e, d);
    numPersonas++;
    cout << "Administrador registrado." << endl;
}

void mostrarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    int indice;
    cout << "Indice del alumno (1 a " << cantidadAlumnos << "): ";
    cin >> indice;
    if (indice < 1 || indice > cantidadAlumnos) {
        cout << "Indice invalido." << endl;
        return;
    }
    alumnos[indice - 1].mostrar();
}

void mostrarTodos() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    for (int i = 0; i < cantidadAlumnos; i++) {
        cout << "Alumno " << i + 1 << ":" << endl;
        alumnos[i].mostrar();
        cout << "---------------------" << endl;
    }
}

void calcularPromedio() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    double suma = 0;
    for (int i = 0; i < cantidadAlumnos; i++) {
        suma += alumnos[i].getEdad();
    }
    double promedio = suma / cantidadAlumnos;
    cout << "Promedio de edades: " << promedio << endl;
}

void buscarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno a buscar: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice != -1) {
        cout << "Alumno encontrado en la posicion " << indice + 1 << ":" << endl;
        alumnos[indice].mostrar();
    } else {
        cout << "Alumno no encontrado." << endl;
    }
}

void eliminarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno a eliminar: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    for (int i = indice; i < cantidadAlumnos - 1; i++) {
        alumnos[i] = alumnos[i + 1];
    }
    cantidadAlumnos--;
    cout << "Alumno eliminado." << endl;
}

void modificarAlumno() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno a modificar: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    string n;
    int e;
    string m;

    cout << "Nuevo nombre: ";
    cin >> n;
    cout << "Nueva edad: ";
    cin >> e;
    cout << "Nueva matricula: ";
    cin >> m;

    alumnos[indice].setNombre(n);
    alumnos[indice].setEdad(e);
    alumnos[indice].setMatricula(m);

    cout << "Alumno modificado." << endl;
}

void agregarMateria() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    if (alumnos[indice].getNumMaterias() >= 10) {
        cout << "No hay espacio para mas materias." << endl;
        return;
    }

    string nombreMateria;
    string clave;

    cout << "Nombre de la materia: ";
    cin >> nombreMateria;
    cout << "Clave de la materia: ";
    cin >> clave;

    Materia m;
    m.setNombre(nombreMateria);
    m.setClave(clave);

    alumnos[indice].agregarMateria(m);
    cout << "Materia agregada." << endl;
}

void registrarCalificacion() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    if (alumnos[indice].getNumCalificaciones() >= 10) {
        cout << "No hay espacio para mas calificaciones." << endl;
        return;
    }

    string clave;
    float nota;

    cout << "Clave de la materia: ";
    cin >> clave;

    if (alumnos[indice].buscarMateria(clave) == -1) {
        cout << "La materia no existe." << endl;
        return;
    }

    cout << "Nota: ";
    cin >> nota;

    Calificacion c;
    c.setClaveMateria(clave);
    c.setNota(nota);

    alumnos[indice].registrarCalificacion(c);
    cout << "Calificacion registrada." << endl;
}

void mostrarHistorial() {
    if (cantidadAlumnos == 0) {
        cout << "No hay alumnos registrados." << endl;
        return;
    }
    string buscar;
    cout << "Nombre del alumno: ";
    cin >> buscar;

    int indice = buscarIndiceAlumno(buscar);

    if (indice == -1) {
        cout << "Alumno no encontrado." << endl;
        return;
    }

    cout << "Historial de " << alumnos[indice].getNombre() << endl;

    for (int i = 0; i < alumnos[indice].getNumMaterias(); i++) {
        Materia m = alumnos[indice].getMateria(i);
        cout << "Materia: " << m.getNombre() << endl;
        cout << "Clave: " << m.getClave() << endl;

        for (int j = 0; j < alumnos[indice].getNumCalificaciones(); j++) {
            Calificacion c = alumnos[indice].getCalificacion(j);
            if (c.getClaveMateria() == m.getClave()) {
                cout << "Nota: " << c.getNota() << endl;
            }
        }
        cout << "---------------------" << endl;
    }
}

void mostrarPersonas() {
    if (numPersonas == 0) {
        cout << "No hay maestros ni administradores registrados." << endl;
        return;
    }
    for (int i = 0; i < numPersonas; i++) {
        cout << "Persona " << i + 1 << ":" << endl;
        personas[i]->mostrar();
        cout << "---------------------" << endl;
    }
}

void menu() {
    int opcion;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Registrar Alumno." << endl;
        cout << "2. Mostrar un Alumno." << endl;
        cout << "3. Mostrar Todos los Alumnos." << endl;
        cout << "4. Calcular Promedio." << endl;
        cout << "5. Buscar Alumno por nombre." << endl;
        cout << "6. Eliminar Alumno." << endl;
        cout << "7. Modificar Alumno." << endl;
        cout << "8. Agregar Materia." << endl;
        cout << "9. Registrar Calificacion." << endl;
        cout << "10. Mostrar Historial Academico." << endl;
        cout << "11. Registrar Maestro." << endl;
        cout << "12. Registrar Administrador." << endl;
        cout << "13. Mostrar Maestros y Administradores." << endl;
        cout << "14. Salir." << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarAlumno();
        } else if (opcion == 2) {
            mostrarAlumno();
        } else if (opcion == 3) {
            mostrarTodos();
        } else if (opcion == 4) {
            calcularPromedio();
        } else if (opcion == 5) {
            buscarAlumno();
        } else if (opcion == 6) {
            eliminarAlumno();
        } else if (opcion == 7) {
            modificarAlumno();
        } else if (opcion == 8) {
            agregarMateria();
        } else if (opcion == 9) {
            registrarCalificacion();
        } else if (opcion == 10) {
            mostrarHistorial();
        } else if (opcion == 11) {
            registrarMaestro();
        } else if (opcion == 12) {
            registrarAdministrador();
        } else if (opcion == 13) {
            mostrarPersonas();
        } else if (opcion == 14) {
            cout << "Saliendo del programa." << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 14);
}

int main() {
    menu();

    for (int i = 0; i < numPersonas; i++) {
        delete personas[i];
    }

    return 0;
}