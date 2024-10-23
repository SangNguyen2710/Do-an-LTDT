#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

typedef struct Vertex
{
public:
	char name;
	bool passed;
	std::vector<int>dinhlienke; 
	std::vector<bool> available;

public:
	bool get_status()
	{
		return this->passed;
	}
	void set_status(bool status)
	{
		this->passed = status;
	}
};

typedef struct Edge
{
public:
	char start;
	char end;

public:
	Edge(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
	// Hàm constructor mặc định
	Edge()
	{
	}
};

typedef struct Graph
{
	int tongsodinh;
	std::vector<struct Vectex>danhsachdinh;
};



bool read_file(const char* pathtxt, std::vector<Vertex> &danhsachdinh)
{
	//Xử lý dấu "" nếu có
	char path[1000];
	int j = 0;
	if (pathtxt[0] == '"' || pathtxt[(strcspn(pathtxt, "\n")) - 1] == '"')
	{
		for (int i = 1; i < strlen(pathtxt); i++)
		{
			if (pathtxt[i] == '\n')
			{
				path[j] = '\0';
				break;
			}
			if (pathtxt[i] == '"') continue;
			path[j++] = pathtxt[i];
		}
	}
	else
	{
		for (int i = 0; i < strlen(pathtxt); i++)
		{
			if (pathtxt[i] == '\n')
			{
				path[i] = '\0';
				break;
			}
			path[i] = pathtxt[i];
		}
	}
	FILE* file;
	fopen_s(&file, path, "r");
	if (file == NULL)
	{
		printf("Khong the mo file, kiem tra lai duong dan");
		return false;
	}
	
	char line[1000];
	while(fgets(line,sizeof(line),file) != NULL)
	{

	}
	
}