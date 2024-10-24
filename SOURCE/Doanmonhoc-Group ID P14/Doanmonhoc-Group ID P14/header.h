#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <algorithm>

typedef struct Vertex
{
public:
	int name;
	int level;
	bool passed;
	std::vector<int> dinhlienke; 
	std::vector<bool> available;
};

typedef struct Edge
{
public:
	int start;
	int end;

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
	std::vector<struct Vertex>danhsachdinh;

	void in_dothi()
	{
		for (int i = 0; i < danhsachdinh.size(); i++)
		{
			printf("So bac cua dinh la %d	", danhsachdinh[i].level);
			for (int j = 0; j < danhsachdinh[i].dinhlienke.size(); j++)
			{
				printf("%d ", danhsachdinh[i].dinhlienke[j]);
			}
			printf("\n");
		}
	}
};



bool read_file(Graph &graph);

void read_line_create_graph(const char *line, Graph &graph);
