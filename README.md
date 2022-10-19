# Hill Climbing First Improvement para Office Space Allocation Problem

## Estructura del código

El programa representa las entidades, las salas y las restricciones mediante clases definidas en `Entity`, `Room` y `Constraint` respectivamente.

Con las funciones definidas en `Extract`, se extraen las entidades, las salas y las restricciones almacenándolas en listas de las clases respectivas.

Mediante las funciones definidas en `Solution` se construye la solución final.

## Ejecución

Para compilar el programa ejecute:

```console
make
```

Para limpiar los archivos de compilación `.o` ejecute:

```console
make clean
```

Para correr el programa ejecute:

```console
make run instance=name_instance
```

Donde `name_instance` es el nombre de la instancia a utilizar. Por ejemplo, para correr el programa con la instancia del archivo `nott1.txt`, se debe ejecutar:

```console
make run instance=nott1
```

## Estructura de las instancias

NoOfEntities:    The number of entities in the instance
NoOfRooms:       The number of rooms in the instance
NoOfFloors:      The number of floors in the floors
NoOfConstraints: The number of total constraints (hard + soft)
NoOfHardConstraints: The number of hard constraints
NoOfSoftConstraints: The number of soft constraints

ENTITIES
Entities are listed as a series of (EID    GID    SPACE) where
EID is the index of the entity,
GID is the group index (that the group the entity belongs to)
SPACE is the space required for the entity

-----------------------------------------------------------------
ROOMS
Rooms are listed as a series of (RID  FID   SPACE    ADJ_LIST)
where
RID is the index of the room
FID is the floor index (that the floor the room belongs to
SPACE is the space capacity of the room
ADJ_LIST is the adjacency list for room RID (the indices for the rooms that are adjacent to RID)
IMPORTANT: A room is considered adjacent to itself as well.
IMPORTANT: The nearby relationship is defined over the floors, the rooms on the same floor is considered near to each other,
Those in different floors are considered away from each other.

-----------------------------------------------------------------

CONSTRAINTS (CID CTYPE SorH C1 C2) where
CID is the index of the constraint
CTYPE is the type of the constraint. The available values are
ALLOCATION_CONSTRAINT 0
NONALLOCATION_CONSTRAINT 1
ONEOF_CONSTRAINT 2
CAPACITY_CONSTRAINT 3
SAMEROOM_CONSTRAINT 4
NOTSAMEROOM_CONSTRAINT 5
NOTSHARING_CONSTRAINT 6
ADJACENCY_CONSTRAINT 7
NEARBY_CONSTRAINT 8
AWAYFROM_CONSTRAINT 9
There is no ONEOF_CONSTRAINT in these instances.

SorH defines if the constraint is hard or soft (0 for soft, 1 for Hard)

C1 and C2 defines the content of the constraint

ALLOCATION_CONSTRAINT: C1 represents the room that the entity should be allocated to. C2 unused (-1)
NONALLOCATION_CONSTRAINT: C1 represents the room that the entity should not be allocated to. C2 unused (-1)
ONEOF_CONSTRAINT: Not used in these instances
CAPACITY_CONSTRAINT: C1 represents the room that should not be overused. C2 unused (-1)
SAMEROOM_CONSTRAINT: C1 and C2 represent two entities that should be in the same room
NOTSAMEROOM_CONSTRAINT: C1 and C2 represent two entities that should not be in the same room
NOTSHARING_CONSTRAINT: C1 represents the entity that should not share the room. C2 unused (-1)
ADJACENCY_CONSTRAINT: C1 and C2 represent two entities that should be in adjacent rooms
NEARBY_CONSTRAINT: C1 and C2 represent two entities that should be in near rooms (same floor)
AWAYFROM_CONSTRAINT: C1 and C2 represent two entities that should not be in near rooms (different floors)

Penalties for each soft constraint
ALLOCATION_CONSTRAINT 20
NONALLOCATION_CONSTRAINT 10
ONEOF_CONSTRAINT 10
CAPACITY_CONSTRAINT 10
SAMEROOM_CONSTRAINT 10
NOTSAMEROOM_CONSTRAINT 10
NOTSHARING_CONSTRAINT 50
ADJACENCY_CONSTRAINT 10
NEARBY_CONSTRAINT 10
AWAYFROM_CONSTRAINT 10
