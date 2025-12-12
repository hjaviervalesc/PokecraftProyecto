# Pokecraft 

Pokecraft es una simulación en C++  donde pokemons en un mapa  participan en un clash royale por la victoria. Cada pokemon tiene tipo (Fuego, Agua, Planta, Eléctrico), vida, armadura, daño y una lista de objetos. La partida  genera pokemons y objetos aleatorios, coloca entidades en un mapa y simula combates entre pokemons.No hay UI incluida en los archivos analizados, la interacción observable es por consola.

Flujo de juego 

1) Inicialización del entorno
- La partida crea un Mapa cuadrado de tamaño N. El mapa está representado por una matriz de Casillas donde cada Casilla puede contener, de forma independiente, un Pokemon y/o un Objeto.
- Se solicita a mapa generar objetos. Cada objeto se instancia  y se coloca en una Casilla libre (es decir, una casilla cuyo campo objeto es nullptr).
- La clase Partida se encarga de crear los  pokemons: llama a crearPokemons que repite crearPokemonAleatorio la cantidad solicitada. Cada pokemon creado recibe un inventario inicial  y se sitúa en una Casilla libre del mapa.

2) Colocación y equipamiento
- Tanto en la generación de mapa como en el equipamiento inicial de pokemons se crean objetos de tipo Arma, Armadura o Botiquín.
- Los objetos en casillas permanecen hasta que un pokemon pase por esa casilla y los recoja.

3) Mecánica de batallas
- En las batallas se compara la velocidad de ambos pokemons. El pokémon con mayor velocidad ataca primero.
- Cada ataque ejecuta Pokemon::atacar; este método invoca calcularDanno en el atacante, que aplica la regla de efectividad según el tipo del objetivo (la lógica de efectividad está implementada en cada subclase: Fuego, Agua, Planta, Eléctrico).
- Por ejemplo, PokemonAgua duplica su daño contra Fuego, Planta duplica su daño contra Agua, y Fuego duplica su daño contra Planta; Eléctrico aplica un pequeño bonus fijo al daño.
- El daño resultante se resta de la vida del objetivo mediante restarVida.
- Uso de objetos antes/durante la batalla: antes de empezar la ronda de intercambio, Partida::usarObjetos se invoca para cada combatiente. Ese método selecciona un objeto del inventario (aleatorio entre los primeros 5, si existen) y lo utiliza:
  - Si es Arma: Arma::utilizar aplica daño directo (según la implementación actual, el arma aplica daño sobre el pokemon que la usa).
  - Si es Armadura: Armadura::utilizar aumenta la armadura del pokemon (annadirArmadura).
  - Si es Botiquín: Botiquin::utilizar (referenciado) restaura vida.
- Final de la batalla: cuando la vida de un pokémon llega a 0 o menos, se marca como no vivo (vivo = false) y la Partida actualiza las estructuras (la casilla queda libre del pokemon, y la lista de participantes se ajusta fuera de la función si procede).

4) Recolección de objetos
- Movimiento y detección: cuando un pokemon queda en una casilla que contiene un Objeto (misma coordenada), la función recolectarObjetos recorre el vector de objetos del mapa y añade al inventario del pokemon los objetos cuyo x,y coincidan.
- Efecto de la recolección: al añadirse al inventario, el objeto se elimina de la lista/posición del mapa (objeto deja de existir en la casilla).

5) Zona azul (daño ambiental)
- Partida::reducirZonaAzul simula un daño ambiental en los bordes de un área cuadrada centrada en (x,y). La función recorre las casillas del perímetro del cuadrado y, si encuentra pokemons, los marca como no vivos y libera la casilla. Este mecanismo permite eliminar entidades fuera del área segura, similar a las zonas de contracción en un battle-royale.

6) Interacción del jugador y automatización
- En la base de código analizada no existe manejo de entrada directa del usuario ni interfaz gráfica: la simulación es automática y está dirigida por las rutinas de Partida (creación, emparejamiento, uso de objetos, zona azul). La salida informativa se realiza mediante std::cout para imprimir eventos relevantes (uso de objetos, resultados de batallas, muertes por zona azul).
- Si se desea introducir control del jugador, sería necesario añadir un módulo de entrada y modificar Partida para aceptar decisiones externas (ej. elegir objeto a usar, moverse manualmente), además de una UI para mostrar el mapa y el estado de las entidades.

Sistemas principales (según código):
- Lógica: clases en C++ (Partida, Mapa, Pokemon, Objeto).
- UI: mensajes por consola (cout) para eventos de batalla y uso de objetos.
- Almacenamiento/Estado: estructura en memoria (vectores y listas), manejo manual de memoria con new/delete.
- Sonido/Audio: no presente en los archivos analizados.
- Input: no presente (no se detectan lecturas de teclado o eventos).

C. Jerarquía de clases completa (profesional)
- Entidad (base común, no incluido)
  - Pokemon (abstracta)
    - PokemonFuego
    - PokemonAgua
    - PokemonPlanta
    - PokemonElectrico
  - Objeto (abstracta)
    - Arma
      - ArmaDiamante
      - (otras armas referenciadas)
    - Armadura
      - ArmaduraCuero
      - ArmaduraHierro
      - ArmaduraDiamante
    - Botiquin (referenciado)

Otras clases:
- Casilla
- Mapa
- Partida
- TiposArma (enum)

D. Explicación técnica de las clases (resúmenes y roles)
- Pokemon: eje de la simulación, contiene estado vital y mecánicas de combate. El patrón principal es herencia con polimorfismo para calculardanno.
- Subclases de Pokemon: encapsulan reglas de modificación de daño según el tipo objetivo.
- Objeto y subclases: implementan efectos sobre pokemons (daño, armadura, curación). Uso polimórfico de 'utilizar'.
- Mapa y Casilla: estructura de representación espacial y contenedor de objetos/entidades.
- Partida: controlador/scheduler de simulación; contiene rutinas para crear pjs, gestionar batallas, usar objetos y aplicar efectos globales (zona azul).

E. Herramientas software empleadas (inferido por el proyecto)
- Lenguaje: C++ (uso de STL, new/delete, headers, .cpp/.h).
- Librerías estándar: <vector>, <list>, <functional>, <memory> (parcialmente usado), <cstdlib>, <ctime>, <iostream>.
- Control de versiones / build system: no presente en los ficheros analizados (no se hallan CMakeLists, .sln o Makefile).
- Motor de juego: no hay uso de Unity/Unreal (proyecto C++ nativo).

## 1) RESUMEN TÉCNICO DEL CÓDIGO

Lista de clases y entidades detectadas (en la carpeta Pokecraft):
- TiposArma (enum) — Enumeración de tipos de arma.
- Pokemon (clase abstracta) — Clase base para todos los pokemons.
- PokemonFuego — Subclase de Pokemon con comportamiento de daño para fuego.
- PokemonAgua — Subclase de Pokemon con comportamiento de daño para agua.
- PokemonPlanta — Subclase de Pokemon con comportamiento de daño para planta.
- PokemonElectrico — Subclase de Pokemon con comportamiento de daño para eléctrico.
- Entidad (referenciada) — Clase base referenciada por Pokemon y Objeto (definición no incluida en los archivos analizados).
- Objeto (clase abstracta) — Clase base para elementos recogibles en el mapa.
- Arma — Subclase de Objeto que inflige daño.
- ArmaDiamante — Subclase de Arma (tipos concretos con dano definido).
- Armadura — Subclase de Objeto que añade resistencia/armadura.
- ArmaduraCuero — Subclase concreta de Armadura.
- ArmaduraHierro — Implementación de ArmaduraHierro (métodos implementados en cpp).
- ArmaduraDiamante — Subclase concreta de Armadura.
- Botiquin (referenciado) — Referenciado en código pero fichero no incluido.
- Casilla — Contenedor de una posición del mapa; contiene punteros a Pokemon y Objeto.
- Mapa — Gestión de la matriz de Casilla y generación de objetos.
- Partida — Lógica de alto nivel: creación de pokemons, batallas, interacción entre mapa y objetos.

Relaciones, dependencias e herencias (resumen):
- Pokemon (abstracta) <- PokemonFuego, PokemonAgua, PokemonPlanta, PokemonElectrico (herencia).
- Objeto (abstracta) <- Arma, Armadura (herencia).
- Arma <- ArmaDiamante (herencia).
- Armadura <- ArmaduraCuero, ArmaduraHierro, ArmaduraDiamante (herencia).
- Mapa contiene MatrizCasillas que almacena Casilla*.
- Casilla contiene pointers: Pokemon* y Objeto*.
- Partida usa Mapa y crea/coloca Pokemons y Objetos en Mapa; referencia tipos de objetos y pokemons.
- Muchas clases heredan de Entidad (no incluido): interfaz común con posición, nombre y estado vivo.

Esquema de jerarquía (texto):
- Entidad (referente)
  - Pokemon (abstracta)
    - PokemonFuego
    - PokemonAgua
    - PokemonPlanta
    - PokemonElectrico
  - Objeto (abstracta)
    - Arma
      - ArmaDiamante
      - (ArmaHierro/ArmaMadera referenciadas pero no implementadas en los ficheros analizados)
    - Armadura
      - ArmaduraCuero
      - ArmaduraHierro
      - ArmaduraDiamante
    - Botiquin (referenciado)

---

## 2) EXPLICACIÓN DETALLADA DE CADA CLASE

Nota: se explica únicamente lo presente en los ficheros analizados. No se incluyen elementos cuyo código no aparece.

### TiposArma (enum)
Responsabilidad: definir los tipos de arma disponibles.
Métodos/miembros: enumeradores: Martillo, Hacha, Espada.
Relaciones: usado por clases Arma* para decidir parametrización de arma.

Mini-diagrama:
TiposArma { Martillo, Hacha, Espada }

---

### Entidad (referenciada)
Responsabilidad (según uso): clase base común que contiene posición (x,y), nombre y estado vivo. No se analiza código fuente aquí (no incluido), pero es base de Pokemon y Objeto.

Mini-diagrama:
Entidad { x, y, vivo, nombre }  // atributos inferidos por uso

---

### Pokemon (Pokemon.h / Pokemon.cpp)
Responsabilidad principal: Representa a una entidad jugable/combativa con vida, objetos, tipo elemental, armadura, daño, velocidad y comportamiento de ataque y movimiento.
Atributos importantes:
- int vida, vidaMax, armadura, danno, velocidad
- std::list<Objeto*>* objetos
- TiposPokemon tipo (archivo TiposPokemon no incluido)
- static int contadorPokemon
- bool controlado
Métodos importantes:
- constructor: inicializa miembros y incrementa contadorPokemon.
- destructor: decrementa contadorPokemon y borra la lista de objetos (si existe).
- getVida(), getObjetos(), getArmadura(), getDanno(), getVelocidad(), getTipo(), getControlado()
- annadirObjeto(Objeto*): añade objeto a la lista.
- annadirVida(int): suma vida sin exceder vidaMax.
- restarVida(int): resta vida y marca vivo=false si <=0.
- annadirArmadura(int): suma armadura.
- moverse(int x, int y): suma desplazamiento.
- atacar(Pokemon*): calcula daño usando calcularDanno en función del tipo del atacado y lo aplica.
- virtual int calcularDanno(TiposPokemon tipoPokemon) = 0; (método abstracto que implementan las subclases)
- setControlado(bool)
Relación con otras clases: depende de Objeto para los objetos que puede portar; es base de las subclases elementales.

Mini-diagrama:
Pokemon
- atributos: vida, vidaMax, armadura, danno, velocidad, objetos, tipo
- métodos: atacar(), moverse(), annadirObjeto(), restarVida(), calcularDanno() (abstracto)

---

### PokemonFuego (PokemonFuego.h / PokemonFuego.cpp)
Responsabilidad: Implementa el comportamiento específico de daño para pokemons de tipo Fuego.
Métodos clave:
- constructor/destructor: gestionan contadorFuego estático.
- calcularDanno(TiposPokemon tipoPokemon): ajusta el daño según el tipo objetivo:
  - Agua: divide daño entre 2
  - Planta: multiplica por 2
  - Fuego/Eléctrico: sin cambio
Relación: hereda de Pokemon, se usa en Partida::crearPokemonAleatorio.

Mini-diagrama:
PokemonFuego : Pokemon
- contadorFuego (static)
- calcularDanno(tipo) -> int

---

### PokemonAgua (PokemonAgua.h / PokemonAgua.cpp)
Responsabilidad: Implementa el comportamiento de daño para pokemons de tipo Agua.
Métodos clave:
- constructor/destructor: gestionan contadorAgua.
- calcularDanno: 
  - Fuego: *2
  - Planta: /2
  - Agua/Eléctrico: sin cambio

Mini-diagrama:
PokemonAgua : Pokemon
- contadorAgua
- calcularDanno(tipo) -> int

---

### PokemonPlanta (PokemonPlanta.h / PokemonPlanta.cpp)
Responsabilidad: Implementa el comportamiento de daño para pokemons planta.
Métodos clave:
- constructor/destructor: gestionan contadorPlanta.
- calcularDanno:
  - Fuego: /2
  - Agua: *2
  - Planta/Electrico: sin cambio

Mini-diagrama:
PokemonPlanta : Pokemon
- contadorPlanta
- calcularDanno(tipo) -> int

---

### PokemonElectrico (PokemonElectrico.h / PokemonElectrico.cpp)
Responsabilidad: Implementa daño para pokemons eléctricos.
Métodos clave:
- constructor/destructor: gestionan contadorElectrico.
- calcularDanno: aplica un multiplicador fijo (danno * 1.1f) — incremento del 10%.
Relación: hereda de Pokemon.

Mini-diagrama:
PokemonElectrico : Pokemon
- contadorElectrico
- calcularDanno(tipo) -> int

---

### Objeto (Objeto.h / Objeto.cpp)
Responsabilidad: Abstracción de un objeto del mapa (armas, armaduras, botiquines, ...). Contiene estado de recogido, número de usos, tipo y posición.
Atributos:
- bool cogido
- int numUsos
- TiposObjeto tipo (definición no incluida)
- hereda de Entidad
Métodos:
- constructor que inicializa miembros
- virtual ~Objeto()
- virtual void utilizar(Pokemon* pokemon) = 0; (abstracto)
- getX(), getY(), getTipoObjeto()
Relación: base para Arma y Armadura; es utilizada por Pokemon (lista de objetos). Mapa coloca Objeto en Casillas.

Mini-diagrama:
Objeto : Entidad
- cogido, numUsos, tipo
- utilizar(Pokemon*) (abstracto)

---

### Arma (Arma.h / Arma.cpp)
Responsabilidad: Implementa objetos que infligen daño inmediato cuando se usan.
Atributos:
- int danno
Métodos:
- utilizar(Pokemon* pokemon): llama a pokemon->restarVida(danno), decrementa numUsos, marca vivo=false cuando numUsos<=0.
- getDanno(), setDanno()
Relación: Hereda de Objeto; ArmaDiamante hereda de Arma.

Mini-diagrama:
Arma : Objeto
- danno
- utilizar(Pokemon*) -> aplica daño

---

### ArmaDiamante (ArmaDiamante.h / ArmaDiamante.cpp)
Responsabilidad: Implementación concreta de Arma con daño mayor según tipo (Martillo/Hacha/Espada).
Métodos:
- constructor: asigna daño según TiposArma (50,80,110).
- destructor.
Relación: Subtipo de Arma.

Mini-diagrama:
ArmaDiamante : Arma
- constructor determina danno por TiposArma

---

### Armadura (Armadura.h / Armadura.cpp)
Responsabilidad: Implementación de objetos que incrementan armadura/resistencia del Pokemon cuando se usan.
Atributos:
- int resistencia
Métodos:
- utilizar(Pokemon* pokemon): llama a pokemon->annadirArmadura(resistencia) y marca vivo = false.
- getResistencia(), setResistencia()
Relación: Hereda de Objeto; ArmaduraCuero/Hierro/Diamante implementan valores concretos.

Mini-diagrama:
Armadura : Objeto
- resistencia
- utilizar(Pokemon*) -> añade armadura al pokemon

---

### ArmaduraCuero / ArmaduraHierro / ArmaduraDiamante
Responsabilidad: Clases concretas que asignan diferentes valores de resistencia según la pieza (Casco, Mallas, Pechera).
Métodos:
- constructores que llaman a setResistencia con valores distintos por tipo de pieza.
- destructores.
Relación: subclases de Armadura.

Mini-diagrama:
ArmaduraCuero : Armadura (resistencia 20/30/50 según pieza)
ArmaduraHierro : Armadura (resistencia 30/50/80 según pieza)
ArmaduraDiamante : Armadura (resistencia 40/80/110 según pieza)

---

### Casilla (Casilla.h / Casilla.cpp)
Responsabilidad: Representa una celda del mapa que puede contener un Pokemon y/o un Objeto.
Atributos:
- Pokemon* pokemon
- Objeto* objeto
Métodos:
- destructor: pone punteros a nullptr (no borra objetos aquí explícitamente).
Relación: usada por Mapa como elementos de la MatrizCasillas.

Mini-diagrama:
Casilla
- pokemon: Pokemon*
- objeto: Objeto*
- ~Casilla()

---

### Mapa (Mapa.h / Mapa.cpp)
Responsabilidad: Gestionar una matriz cuadrada de Casilla*, crear mapa y generar objetos aleatorios en casillas libres.
Atributos:
- std::vector<std::vector<Casilla*>> MatrizCasillas
Constructores/Métodos:
- Mapa(int tamaño, int nObjetos): crea mapa y genera objetos.
- CrearMapa(int tamaño): redimensiona y crea Casilla*.
- GenerarObjetos(int nObjetos): utiliza un vector de 'fábricas' (std::function<Objeto*()>) para crear objetos aleatorios (ArmaduraCuero/Hierro/Diamante, ArmaMadera/Hierro/Diamante, Botiquin).
  - Coloca objetos en casillas aleatorias no ocupadas.
Relación: usada por Partida; contiene Casillas y por tanto referencias a Pokemons y Objetos posicionados.

Mini-diagrama:
Mapa
- MatrizCasillas : vector<vector<Casilla*>>
- CrearMapa(tamaño), GenerarObjetos(n)

---

### Partida (Partida.h / Partida.cpp)
Responsabilidad principal: Lógica de alto nivel de la simulación/partida:
- creación de pokemons,
- resolución de batallas entre pokemons,
- gestión y distribución de objetos,
- aplicaciones de efectos como la “zona azul”.
Métodos relevantes:
- crearPokemons(int cantidad): crea varios pokemons llamando crearPokemonAleatorio.
- crearPokemonAleatorio(): crea una instancia concreta (Fuego/Agua/Planta/Electrico) con parámetros aleatorios (vida fija 350, daño aleatorio, velocidad aleatoria), los coloca en el Mapa en una casilla libre y les asigna objetos iniciales.
- equipInicio(): devuelve una std::list<Objeto*>* con objetos iniciales (aleatorio entre 3 tipos de equipación).
- batalla(std::vector<Pokemon*>& lista, Pokemon* actual, Pokemon* rival): gestiona turnos de ataque según velocidad, aplica ataques hasta que uno muere, determina indice de eliminación y marca vivo=false.
- objetosMapa(): fábrica que devuelve un vector<Objeto*> con un objeto aleatorio (similar a GenerarObjetos).
- recolectarObjetos(std::vector<Objeto*>& objetos, Pokemon* pokemon): función libre (no miembro) que traslada objetos del mapa al inventario si coordenadas coinciden.
- usarObjetos(Pokemon* pokemonDuelo): selecciona un objeto aleatorio de los primeros 5 del inventario y lo utiliza (Arma, Armadura o Botiquin) y muestra por consola la acción.
- reducirZonaAzul(int x, int y): elimina pokemons en el borde de un cuadrado centrado en (x,y) (simula daño de zona), marcándolos no vivos y liberando la casilla.
Relación con otras clases: usa Mapa, Casilla, Pokemon*, Objeto* y todas las subclases concretas para generar y simular el juego.

Mini-diagrama:
Partida
- mapa : Mapa*
- crearPokemons(), crearPokemonAleatorio(), batalla(), equipInicio(), usarObjetos(), reducirZonaAzul(), objetosMapa()

---







F. Conclusiones (mejoras y limitaciones)
- Limitaciones actuales:
  - Muchas dependencias referenciadas (Entidades base, TiposPokemon, TiposObjeto, Botiquin, ArmaHierro, ArmaMadera) no están incluidas en los ficheros entregados; hace el árbol incompleto.
  - Gestión manual de memoria: potenciales fugas y riesgos (necesaria normalización con smart pointers).
  - No hay interfaz de usuario ni manejo de entrada, la simulación es por consola.
  - Algunas funciones (e.g., destructor de Casilla) no liberan recursos, solo dejan punteros a nullptr — revisar propiedad/ownership.
- Mejoras propuestas:
  - Reemplazar gestión manual de punteros por smart pointers (std::unique_ptr / std::shared_ptr) para evitar fugas.
  - Centralizar fábricas de objetos en un módulo/factory para evitar duplicación (se repite lógica de fabricas en Mapa y Partida).
  - Añadir un manejador de recursos y un manager de partidas que controle ciclos completos (turnos, eliminación segura de objetos/pokemons).
  - Exponer una API mínima para controlar la simulación (start/pause/step) y, si procede, añadir una UI (con SDL/ImGui) para visualizar mapa.
  - Agregar tests unitarios para calcular daños y comportamiento de objetos.
- Valoración final:
  - Código con estructura clara y orientado a OOP: separación entre entidades, objetos y control de juego.
  - Buen uso de polimorfismo para las reglas de daño según tipo.
  - Necesita completar ficheros faltantes y robustecer gestión de memoria/ownership antes de ser usado en producción.

---

## 4) README.md PROFESIONAL (resumen y guía de uso)

Pokecraft — Simulador de encuentros tipo "pokemon" (C++)
======================================================

Descripción
-----------
Pokecraft es un proyecto en C++ que simula encuentros entre entidades tipo "pokemon" en un mapa cuadrado. Cada entidad tiene tipo elemental, vida, armadura y puede portar objetos (armas, armaduras, botiquines). El motor permite generar pokemons y objetos aleatorios, colocarlos en el mapa, y simular batallas por turnos.

Características principales
---------------------------
- Sistema de tipos elementales (Fuego, Agua, Planta, Eléctrico) con reglas de daño.
- Objetos equipables: Armas (infligen daño), Armaduras (añaden armadura), Botiquines (curación — referenciado).
- Mapa con Casillas que contienen Pokemons y Objetos.
- Simulación automatizada de batallas por turnos, ordenadas por velocidad.
- Generación aleatoria de pokemons y objetos.

Cómo ejecutar (observaciones)
-----------------------------
- Este repositorio contiene la lógica del juego en C++ (archivos .h/.cpp).
- No existe un script de compilación incluido en los archivos analizados.
- Recomendación para compilar:
  - Crear un proyecto en su IDE C++ preferido (Visual Studio / g++).
  - Añadir todos los .cpp/.h de la carpeta Pokecraft al proyecto.
  - Definir y proporcionar ficheros faltantes referenciados (Entidad.h/cpp, TiposPokemon.h, TiposObjeto.h, TiposArmadura.h, Botiquin.h, ArmaHierro/ArmaMadera si es necesario).
  - Compilar y ejecutar el ejecutable resultante; la salida usa std::cout para eventos.

Requisitos del sistema
----------------------
- Compilador C++ moderno (soporte C++11 o superior).
- Plataformas: Windows / Linux / macOS (dependiendo del compilador).
- Memoria: según número de pokemons/objetos (uso dinámico con new/delete).

Estructura de carpetas (relevante)
---------------------------------
- Pokecraft/
  - Pokemon*.h/.cpp — clases Pokemon y subtipos
  - Objeto*.h/.cpp — objetos (Arma, Armadura, etc.)
  - Mapa.h/.cpp — mapa y colocación de objetos
  - Partida.h/.cpp — lógica de creación y batalla
  - Casilla.h/.cpp — celda del mapa
  - TiposArma.h — enumeraciones

Clases más importantes y su rol
-------------------------------
- Pokemon (base): representa luchadores; polimorfismo para calcular daño.
- PokemonFuego/Agua/Planta/Electrico: reglas elementales de daño.
- Objeto (base): objetos del mundo; Arma y Armadura concretan el comportamiento.
- Mapa: estructura espacial.
- Partida: controlador de la simulación (crea pokemons, resuelve batallas, gestiona objetos y zona azul).

Instrucciones de instalación (sugeridas)
---------------------------------------
1. Abrir su IDE y crear un nuevo proyecto C++.
2. Añadir todos los ficheros .cpp y .h de la carpeta Pokecraft.
3. Añadir o implementar ficheros referenciados que no están incluidos (Entidad, TiposPokemon, TiposObjeto, Botiquin, etc.).
4. Compilar con soporte C++11 o superior.
5. Ejecutar; observar la salida por consola para eventos de batalla.

Proyecto desarrollado en C++ (Visual Studio) por Javi Hilario, Jose Moreno y Alex.

Breve descripción añadida:
Pokecraft es un battle-royale automático inspirado en Pokémon. Las entidades son pokemons de tipo Fuego, Agua, Planta o Eléctrico. Las reglas de efectividad implementadas en el código son:
- Fuego hace más daño a Planta (x2) y menos a Agua (/2).
- Planta hace más daño a Agua (x2) y menos a Fuego (/2).
- Agua hace más daño a Fuego (x2) y menos a Planta (/2).
- Eléctrico aplica un pequeño bonus fijo al daño (implementado como +10% en la clase correspondiente).

El equipamiento se genera aleatoriamente en el mapa e incluye:
- Armas (ej. martillo, hacha, espada).
- Armaduras (casco, mallas, pechera).
- Botiquines (curación).

La simulación se ejecuta desde la lógica del motor (Partida, Mapa, Pokemon, Objeto). El código contiene métodos para crear pokemons y objetos aleatorios, colocarlos en el mapa y resolver enfrentamientos automáticamente. El método moverse existe en la clase Pokemon para modificar posición (la gestión del movimiento en la simulación depende de la lógica de Partida).

Créditos
--------
- Proyecto realizado en C++ (Visual Studio).
- Autores: Javi Hilario, Jose Moreno y Alex.
- (añadir otros colaboradores o detalles adicionales si procede).

---

Notas finales y recomendaciones de mantenimiento
- Completar y añadir los ficheros referenciados faltantes para obtener un sistema funcional.
- Migrar hacia smart pointers para robustez en gestión de memoria.
- Añadir un sistema de build (CMake) y documentación adicional (Doxygen) si se desea producción mantenible.

