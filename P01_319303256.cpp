#include <stdio.h>
#include <string.h>
#include <glew.h>	
#include <glfw3.h>
#include <cstdlib>
#include <Windows.h>
#include <ctime>

//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, shader;

//Vertex Shader
//recibir color, salida Vcolor
static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,1.0f); 			\n\
}";
//recibir Vcolor y dar de salida color
static const char* fShader = "						\n\
#version 330										\n\
out vec4 color;										\n\
void main()											\n\
{													\n\
	color = vec4(1.0f,1.0f,0.0f,1.0f);	 			\n\
}";



void CrearTriangulo()
{
	GLfloat vertices[] = {

		//Para la letra E

		//1
		-0.39f, 0.60f, 0.0f,
		-0.56f, 0.40f, 0.0f,
		-0.56f, 0.60f, 0.0f,

		//2
		-0.56f, 0.60f, 0.0f,
		-0.67f, 0.40f, 0.0f,
		-0.56f, 0.40f, 0.0f,

		//3
		-0.56f, 0.60f, 0.0f,
		-0.90f, 0.60f, 0.0f,
		-0.90f, 0.00f, 0.0f,

		//4
		-0.73f, 0.30f, 0.0f,
		-0.90f, 0.00f, 0.0f,
		-0.73f, -0.29f, 0.0f,

		//5
		-0.90f, 0.00f, 0.0f,
		-0.90f, -0.60f, 0.0f,
		-0.56f, -0.60f, 0.0f,

		//6
		-0.73f, -0.29f, 0.0f,
		-0.39f, -0.29f, 0.0f,
		-0.56f, -0.60f, 0.0f,

		//7
		-0.73f, 0.16f, 0.0f,
		-0.73f, -0.10f, 0.0f,
		-0.47f, 0.16f, 0.0f,

		//8
		-0.47f, -0.10f, 0.0f,
		-0.73f, -0.10f, 0.0f,
		-0.47f, 0.16f, 0.0f,

		//9
		-0.39f, 0.60f, 0.0f,
		-0.56f, 0.40f, 0.0f,
		-0.39f, 0.40f, 0.0f,

		//10
		-0.39f, -0.29f, 0.0f,
		-0.56f, -0.60f, 0.0f,
		-0.39f, -0.60f, 0.0f,

		//11
		-0.67f, 0.40f, 0.0f,
		-0.56f, 0.40f, 0.0f,
		-0.73f, 0.30f, 0.0f,

		//12
		-0.56f, 0.40f, 0.0f,
		-0.39f, 0.40f, 0.0f,
		-0.73f, 0.30f, 0.0f,

		//13
		-0.73f, 0.30f, 0.0f,
		-0.39f, 0.40f, 0.0f,
		-0.39f, 0.30f, 0.0f,

		//Para la letra H

		//1
		-0.355f, 0.60f, 0.0f,
		-0.100f, 0.60f, 0.0f,
		-0.355f, 0.16f, 0.0f,

		//2
		-0.100f, 0.60f, 0.0f,
		-0.355f, 0.16f, 0.0f,
		-0.100f, 0.16f, 0.0f,

		//3
		-0.355f, 0.16f, 0.0f,
		-0.100f, 0.16f, 0.0f,
		-0.100f, -0.10f, 0.0f,

		//4
		-0.355f, 0.16f, 0.0f,
		-0.100f, -0.10f, 0.0f,
		-0.355f, -0.10f, 0.0f,

		//5
		-0.100f, -0.10f, 0.0f,
		-0.355f, -0.10f, 0.0f,
		-0.355f, -0.60f, 0.0f,

		//6
		-0.100f, -0.10f, 0.0f,
		-0.355f, -0.60f, 0.0f,
		-0.100f, -0.60f, 0.0f,

		//7
		-0.100f, 0.16f, 0.0f,
		0.070f, 0.16f, 0.0f,
		-0.100f, -0.10f, 0.0f,

		//8
		0.070f, 0.16f, 0.0f,
		-0.100f, -0.10f, 0.0f,
		0.070f, -0.10f, 0.0f,

		//9
		0.070f, 0.60f, 0.0f,
		0.325f, 0.60f, 0.0f,
		0.070f, 0.16f, 0.0f,

		//10
		0.325f, 0.60f, 0.0f,
		0.070f, 0.16f, 0.0f,
		0.325f, 0.16f, 0.0f,

		//11
		0.070f, 0.16f, 0.0f,
		0.325f, 0.16f, 0.0f,
		0.325f, -0.10f, 0.0f,

		//12
		0.070f, 0.16f, 0.0f,
		0.325f, -0.10f, 0.0f,
		0.070f, -0.10f, 0.0f,

		//13
		0.325f, -0.10f, 0.0f,
		0.070f, -0.10f, 0.0f,
		0.070f, -0.60f, 0.0f,

		//14
		0.325f, -0.10f, 0.0f,
		0.070f, -0.60f, 0.0f,
		0.325f, -0.60f, 0.0f,

		//Para la letra R

		//1
		0.43f, 0.60f, 0.0f,  
		0.54f, 0.59f, 0.0f,  
		0.43f, -0.60f, 0.0f,  

		//2
		0.54f, 0.59f, 0.0f, 
		0.43f, -0.60f, 0.0f,  
		0.55f, -0.60f, 0.0f,  

		//3
		0.54f, 0.12f, 0.0f,  
		0.54f, 0.0f, 0.0f,   
		0.58f, 0.12f, 0.0f,  

		//4
		0.54f, 0.0f, 0.0f,   
		0.58f, 0.12f, 0.0f,  
		0.60f, 0.0f, 0.0f,   

		//5
		0.58f, 0.12f, 0.0f,  
		0.60f, 0.0f, 0.0f,   
		0.64f, 0.12f, 0.0f,  

		//6
		0.60f, 0.0f, 0.0f,   
		0.64f, 0.12f, 0.0f,  
		0.69f, 0.14f, 0.0f,  

		//7
		0.69f, 0.14f, 0.0f,  
		0.67f, 0.0f, 0.0f,   
		0.60f, 0.0f, 0.0f,   

		//8
		0.69f, 0.14f, 0.0f,  
		0.67f, 0.0f, 0.0f,   
		0.74f, 0.0f, 0.0f,   

		//9
		0.74f, 0.0f, 0.0f,  
		0.69f, 0.14f, 0.0f,  
		0.80f, 0.03f, 0.0f,  

		//10
		0.69f, 0.14f, 0.0f,  
		0.80f, 0.03f, 0.0f,  
		0.85f, 0.09f, 0.0f,  

		//11
		0.69f, 0.14f, 0.0f,  
		0.85f, 0.09f, 0.0f,  
		0.88f, 0.20f, 0.0f,  

		//12
		0.69f, 0.14f, 0.0f,  
		0.88f, 0.20f, 0.0f,  
		0.73f, 0.18f, 0.0f,  

		//13
		0.88f, 0.20f, 0.0f,  
		0.73f, 0.18f, 0.0f,  
		0.88f, 0.31f, 0.0f,  

		//14
		0.73f, 0.18f, 0.0f, 
		0.88f, 0.31f, 0.0f, 
		0.86f, 0.42f, 0.0f,  

		//15
		0.86f, 0.42f, 0.0f,  
		0.73f, 0.18f, 0.0f,  
		0.75f, 0.26f, 0.0f,  

		//16
		0.75f, 0.26f, 0.0f,  
		0.86f, 0.42f, 0.0f,  
		0.74f, 0.33f, 0.0f,  

		//17
		0.86f, 0.42f, 0.0f, 
		0.73f, 0.38f, 0.0f,  
		0.74f, 0.33f, 0.0f,  

		//18
		0.86f, 0.42f, 0.0f,  
		0.73f, 0.38f, 0.0f,  
		0.82f, 0.51f, 0.0f,  

		//19
		0.73f, 0.38f, 0.0f,  
		0.82f, 0.51f, 0.0f,  
		0.73f, 0.56f, 0.0f,  

		//20
		0.73f, 0.38f, 0.0f,  
		0.73f, 0.56f, 0.0f,  
		0.68f, 0.43f, 0.0f,  

		//21
		0.73f, 0.56f, 0.0f,  
		0.68f, 0.43f, 0.0f,  
		0.64f, 0.58f, 0.0f,  

		//22
		0.68f, 0.43f, 0.0f,  
		0.64f, 0.58f, 0.0f,  
		0.54f, 0.59f, 0.0f,  

		//23
		0.68f, 0.43f, 0.0f,  
		0.54f, 0.59f, 0.0f,  
		0.61f, 0.45f, 0.0f,  

		//24
		0.54f, 0.59f, 0.0f,  
		0.61f, 0.45f, 0.0f,  
		0.54f, 0.45f, 0.0f,  

		// Para el palito de abajo

		//25
		0.60f, 0.0f, 0.0f, 
		0.75f, -0.60f, 0.0f,
		0.90f, -0.60f, 0.0f, 

		//26
		0.60f, 0.0f, 0.0f,  
		0.90f, -0.60f, 0.0f, 
		0.74f, 0.0f, 0.0f   	
	};

	glGenVertexArrays(1, &VAO); //generar 1 VAO
	glBindVertexArray(VAO);//asignar VAO

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es est�tico pues no se modificar�n los valores

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(0);
	//agregar valores a v�rtices y luego declarar un nuevo vertexAttribPointer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}


void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) //Funci�n para agregar los shaders a la tarjeta gr�fica
//the Program recibe los datos de theShader

{
	GLuint theShader = glCreateShader(shaderType);//theShader es un shader que se crea de acuerdo al tipo de shader: vertex o fragment
	const GLchar* theCode[1];
	theCode[0] = shaderCode;//shaderCode es el texto que se le pasa a theCode
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);//longitud del texto
	glShaderSource(theShader,1, theCode, codeLength);//Se le asigna al shader el c�digo
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevenci�n de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n",shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el c�digo a la tarjeta gr�fica
}

void CompileShaders() {
	shader= glCreateProgram(); //se crea un programa
	if (!shader)
	{
		printf("Error creando el shader");
		return;
	}
	AddShader(shader, vShader, GL_VERTEX_SHADER);//Agregar vertex shader
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);//Agregar fragment shader
	//Para terminar de linkear el programa y ver que no tengamos errores
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glLinkProgram(shader);//se linkean los shaders a la tarjeta gr�fica
	 //verificaciones y prevenci�n de errores
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al linkear es: %s \n", eLog);
		return;
	}
	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al validar es: %s \n", eLog);
		return;
	}
}
int main()
{

	srand(time(NULL));

	//Inicializaci�n de GLFW
	if (!glfwInit())
	{
		printf("Fall� inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Primer ventana", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tama�o de Buffer
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fall� inicializaci�n de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);

 //Crear tr�angulo
	CrearTriangulo();
	CompileShaders();

	//Cambiar los colores de forma randon.
	float tiempo = 0.0f;
	while (!glfwWindowShouldClose(mainWindow))
	{
	
		static double ultimoCambio = 0.0;
		double tiempoActual = glfwGetTime();

		if (tiempoActual - ultimoCambio >= 2.0)
		{
			ultimoCambio = tiempoActual;

			int color = rand() % 3;

			if (color == 0) {
				glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Rojo
			}
			else if (color == 1) {
				glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // Verde
			}
			else {
				glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Azul
			}
		}

		//Recibir eventos del usuario
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 171); //Nos permite dibujar, puntos, lineas y triangulos.
		glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(mainWindow);

	}

	return 0;
}