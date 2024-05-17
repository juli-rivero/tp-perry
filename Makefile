# Variables
CC = gcc
CFLAGS = -std=c99 -Wall -Wconversion -Werror -lm
CFILES = *.c
TARGET = juego


# Regla para el archivo objetivo
$(TARGET):
	$(CC) $(CFILES) -o $(TARGET) $(CFLAGS) 

# Limpiar los archivos generados
clean:
	rm -f $(TARGET)

# Regla para reconstruir desde cero
rebuild: clean all

#Comprobar errores
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

#Jugar
run: $(TARGET)
	./$(TARGET)

# Regla por defecto (all)
all: $(TARGET)