
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al código
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";
//shaders creados para las figuras
static const char* vShaderAzul = "shaders/shaderazul.vert";
static const char* vShaderVerde = "shaders/shaderverde.vert";
static const char* vShaderVerde2 = "shaders/shaderverde2.vert";
static const char* vShaderRojo = "shaders/shaderrojo.vert";
static const char* vShaderCafe = "shaders/shadercafe.vert";

float angulo = 0.0f;

void Piramides()
{
	unsigned int indices[] = { 
		0,1,2,
		1,3,2,
		3,0,2,
		1,0,3
		
	};
	GLfloat PiramideAzul[] = {
		-0.6f, -0.4f,0.0f,	//0
		0.6f,-0.4f,0.0f,	//1
		0.0f,0.4f, -0.25f,	//2
		0.0f,-0.4f,-0.5f,	//3

	};
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(PiramideAzul, indices, 12, 12);
	meshList.push_back(obj1);

	GLfloat PiramideVerde[] = {
		-0.2f, -0.2f,0.0f,	//0
		0.2f,-0.2f,0.0f,	//1
		0.0f,0.4f, -0.25f,	//2
		0.0f,-0.2f,-0.5f,	//3

	};
	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(PiramideVerde, indices, 12, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(PiramideVerde, indices, 12, 12);
	meshList.push_back(obj3);
}

//Vértices de un cubo
void Cubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

GLfloat cubo_verde[] = {
	// front
	-0.16f,	-0.2f,		0.5f,
	0.16f,	-0.2f,		0.5f,
	0.16f,	0.2f,		0.5f,
	-0.16f,	0.2f,		0.5f,
	// back
	-0.16f,	-0.2f,		-0.5f,
	0.16f,	-0.2f,		-0.5f,
	0.16f,	0.2f,		-0.5f,
	-0.16f,	0.2f,		-0.5f,
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_verde, cubo_indices,24, 36);
meshList.push_back(cubo);

Mesh *cubo2 = new Mesh();
cubo2->CreateMesh(cubo_verde, cubo_indices, 24, 36);
meshList.push_back(cubo2);

Mesh* cubo3 = new Mesh();
cubo3->CreateMesh(cubo_verde, cubo_indices, 24, 36);
meshList.push_back(cubo3);

GLfloat cubo_rojo[] = {
	// front
	-0.45f,	-0.6f,		0.5f, //0
	0.45f,	-0.6f,		0.5f, //1
	0.45f,	0.6f,		0.5f, //2
	-0.45f,	0.6f,		0.5f, //3
	// back
	-0.45f,	-0.6f,		-0.5f, //4
	0.45f,	-0.6f,		-0.5f, //5
	0.45f,	0.6f,		-0.5f, //6
	-0.45f,	0.6f,		-0.5f, //7
};
Mesh* cubo4 = new Mesh();
cubo4->CreateMesh(cubo_rojo, cubo_indices, 24, 36);
meshList.push_back(cubo4);

GLfloat cubo_cafe[] = {
	// front
	-0.1f,	-0.12f,		0.5f,
	0.1f,	-0.12f,		0.5f,
	0.1f,	0.12f,		0.5f,
	-0.1f,	0.12f,		0.5f,
	// back
	-0.1f,	-0.12f,		-0.5f,
	0.1f,	-0.12f,		-0.5f,
	0.1f,	0.12f,		-0.5f,
	-0.1f,	0.12f,		-0.5f,
};
Mesh* cubo5 = new Mesh();
cubo5->CreateMesh(cubo_cafe, cubo_indices, 24, 36);
meshList.push_back(cubo5);

Mesh* cubo6 = new Mesh();
cubo6->CreateMesh(cubo_cafe, cubo_indices, 24, 36);
meshList.push_back(cubo6);

}

void Letras()
{
	GLfloat letraE[] = {
		//1
		-0.39f,  0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f,  0.60f,  0.0f,   0.0f, 0.0f, 1.0f,

		//2
		-0.56f,  0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.67f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,

		//3
		-0.56f,  0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.90f,  0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.90f,  0.00f,  0.0f,   0.0f, 0.0f, 1.0f,

		//4
		-0.73f,  0.30f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.90f,  0.00f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.73f, -0.29f,  0.0f,   0.0f, 0.0f, 1.0f,

		//5
		-0.90f,  0.00f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.90f, -0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f, -0.60f,  0.0f,   0.0f, 0.0f, 1.0f,

		//6
		-0.73f, -0.29f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.39f, -0.29f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f, -0.60f,  0.0f,   0.0f, 0.0f, 1.0f,

		//7
		-0.73f,  0.16f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.73f, -0.10f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.47f,  0.16f,  0.0f,   0.0f, 0.0f, 1.0f,

		//8
		-0.47f, -0.10f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.73f, -0.10f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.47f,  0.16f,  0.0f,   0.0f, 0.0f, 1.0f,

		//9
		-0.39f,  0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.39f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,

		//10
		-0.39f, -0.29f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f, -0.60f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.39f, -0.60f,  0.0f,   0.0f, 0.0f, 1.0f,

		//11
		-0.67f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.56f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.73f,  0.30f,  0.0f,   0.0f, 0.0f, 1.0f,

		//12
		-0.56f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.39f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.73f,  0.30f,  0.0f,   0.0f, 0.0f, 1.0f,

		//13
		-0.73f,  0.30f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.39f,  0.40f,  0.0f,   0.0f, 0.0f, 1.0f,
		-0.39f,  0.30f,  0.0f,   0.0f, 0.0f, 1.0f,

	};
	MeshColor* letra = new MeshColor();
	letra->CreateMeshColor(letraE, 234);
	meshColorList.push_back(letra);

	GLfloat letraH[] = {
		//1
		-0.355f,  0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f,  0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.355f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,

		//2
		-0.100f,  0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.355f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,

		//3
		-0.355f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,

		//4
		-0.355f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.355f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,

		//5
		-0.100f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.355f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.355f, -0.60f,  0.0f,   0.0f, 1.0f, 0.0f,

		//6
		-0.100f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.355f, -0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f, -0.60f,  0.0f,   0.0f, 1.0f, 0.0f,

		//7
		-0.100f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		 0.070f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,

		//8
		0.070f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		-0.100f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,

		//9
		0.070f,  0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.325f,  0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,

		//10
		0.325f,  0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.325f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,

		//11
		0.070f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.325f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.325f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,

		//12
		0.070f,  0.16f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.325f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,

		//13
		0.325f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f, -0.60f,  0.0f,   0.0f, 1.0f, 0.0f,

		//14
		0.325f, -0.10f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.070f, -0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
		0.325f, -0.60f,  0.0f,   0.0f, 1.0f, 0.0f,
	};
	MeshColor* letra2 = new MeshColor();
	letra2->CreateMeshColor(letraH, 252);
	meshColorList.push_back(letra2);

	GLfloat letraR[] = {

		//1
		0.43f, 0.60f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.54f, 0.59f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.43f, -0.60f, 0.0f, 1.0f, 0.0f, 0.0f,

		//2
		0.54f, 0.59f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.43f, -0.60f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.55f, -0.60f, 0.0f, 1.0f, 0.0f, 0.0f,

		//3
		0.54f, 0.12f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.54f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.58f, 0.12f, 0.0f, 1.0f, 0.0f, 0.0f,

		//4
		0.54f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.58f, 0.12f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.60f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		//5
		0.58f, 0.12f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.60f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.64f, 0.12f, 0.0f, 1.0f, 0.0f, 0.0f,

		//6
		0.60f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.64f, 0.12f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,

		//7
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.67f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.60f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		 
		//8
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.67f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.74f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		//9
		0.74f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.80f, 0.03f, 0.0f, 1.0f, 0.0f, 0.0f,

		//10
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.80f, 0.03f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.85f, 0.09f, 0.0f, 1.0f, 0.0f, 0.0f,

		//11 
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.85f, 0.09f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.88f, 0.20f, 0.0f, 1.0f, 0.0f, 0.0f,

		//12
		0.69f, 0.14f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.88f, 0.20f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.18f, 0.0f, 1.0f, 0.0f, 0.0f,

		//13
		0.88f, 0.20f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.18f, 0.0f, 1.0f, 0.0f, 0.0f, 
		0.88f, 0.31f, 0.0f, 1.0f, 0.0f, 0.0f,

		//14
		0.73f, 0.18f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.88f, 0.31f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.86f, 0.42f, 0.0f, 1.0f, 0.0f, 0.0f,

		//15 
		0.86f, 0.42f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.18f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.75f, 0.26f, 0.0f, 1.0f, 0.0f, 0.0f,

		//16
		0.75f, 0.26f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.86f, 0.42f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.74f, 0.33f, 0.0f, 1.0f, 0.0f, 0.0f,

		//17
		0.86f, 0.42f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.38f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.74f, 0.33f, 0.0f, 1.0f, 0.0f, 0.0f,

		//18
		0.86f, 0.42f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.38f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.82f, 0.51f, 0.0f, 1.0f, 0.0f, 0.0f,

		//19
		0.73f, 0.38f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.82f, 0.51f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.56f, 0.0f, 1.0f, 0.0f, 0.0f,

		//20
		0.73f, 0.38f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.73f, 0.56f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.68f, 0.43f, 0.0f, 1.0f, 0.0f, 0.0f,

		//21 
		0.73f, 0.56f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.68f, 0.43f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.64f, 0.58f, 0.0f, 1.0f, 0.0f, 0.0f,

		//22
		0.68f, 0.43f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.64f, 0.58f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.54f, 0.59f, 0.0f, 1.0f, 0.0f, 0.0f,

		//23
		0.68f, 0.43f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.54f, 0.59f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.61f, 0.45f, 0.0f, 1.0f, 0.0f, 0.0f,

		//24
		0.54f, 0.59f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.61f, 0.45f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.54f, 0.45f, 0.0f, 1.0f, 0.0f, 0.0f,

		// Para el palito de abajo

		//25
		0.60f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.75f, -0.60f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.90f, -0.60f, 0.0f, 1.0f, 0.0f, 0.0f,

		//26 
		0.60f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.90f, -0.60f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.74f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f
	};

	MeshColor* letra3 = new MeshColor();
	letra3->CreateMeshColor(letraR, 468);
	meshColorList.push_back(letra3);
}

void CreateShaders()
{

	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader *shader2 = new Shader();
	shader2->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader2);

	Shader* shader3 = new Shader();
	shader3->CreateFromFiles(vShaderVerde, fShader);
	shaderList.push_back(*shader3);

	Shader* shader4 = new Shader();
	shader4->CreateFromFiles(vShaderVerde2, fShader);
	shaderList.push_back(*shader4);

	Shader* shader5 = new Shader(); 
	shader5->CreateFromFiles(vShaderRojo, fShader);
	shaderList.push_back(*shader5);

	Shader* shader6 = new Shader(); 
	shader6->CreateFromFiles(vShaderCafe, fShader);
	shaderList.push_back(*shader6);

	Shader* shader7 = new Shader();
	shader7->CreateFromFiles(vShaderAzul, fShader);
	shaderList.push_back(*shader7);
}


int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	Piramides(); //índice 0 en MeshList
	Cubo();//índice 1 en MeshList
	Letras(); //usa MeshColor, índices en MeshColorList
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	//Projection: Matriz de Dimensión 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	//glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	
	//Model: Matriz de Dimensión 4x4 en la cual se almacena la multiplicación de las transformaciones geométricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad
	
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad

		//Ejercicio numero1
		shaderList[1].useShader();
		uniformModel = shaderList[1].getModelLocation();
		uniformProjection = shaderList[1].getProjectLocation();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[0]->RenderMeshColor();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[1]->RenderMeshColor();

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[2]->RenderMeshColor();

		//Ejercicio numero2

		////Para PIRAMIDE AZUL
		//shaderList[6].useShader();
		//uniformModel = shaderList[6].getModelLocation();
		//uniformProjection = shaderList[6].getProjectLocation();
		////Para piramide azul
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.0f, 0.6f, -4.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[0]->RenderMesh();


		////Para PIRAMIDE VERDE
		//shaderList[2].useShader();
		//uniformModel = shaderList[2].getModelLocation();
		//uniformProjection = shaderList[2].getProjectLocation();
		////Para primer piramide verde
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-0.70f, -0.60f, -3.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[1]->RenderMesh();
		////Para segunda piramide verde
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.70f, -0.60f, -3.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[2]->RenderMesh();


		////Para CUBO VERDE
		//shaderList[3].useShader();
		//uniformModel = shaderList[3].getModelLocation();
		//uniformProjection = shaderList[3].getProjectLocation();
		////Para primer cubo verde 
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-0.22f, -0.1f, -4.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[3]->RenderMesh();
		////Para segundo cubo verde
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.22f, -0.1f, -4.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[4]->RenderMesh();
		////Para tercer cubo verde
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.0f, -0.8f, -4.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[5]->RenderMesh();


		////PARA CUBO ROJO
		//shaderList[4].useShader();
		//uniformModel = shaderList[4].getModelLocation();
		//uniformProjection = shaderList[4].getProjectLocation();
		////Para primer cubo rojo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.0f, -0.4f, -10.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[6]->RenderMesh();

		////PARA CUBO CAFE
		//shaderList[5].useShader();
		//uniformModel = shaderList[5].getModelLocation();
		//uniformProjection = shaderList[5].getProjectLocation();
		////Para primer cubo cafe
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-0.70f, -0.90f, -2.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[7]->RenderMesh(); 
		////Para segundo cubo cafe
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.70f, -0.90f, -2.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		//meshList[8]->RenderMesh();

		glUseProgram(0);
		mainWindow.swapBuffers();
	}

	return 0;
}