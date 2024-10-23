#include "header.h"
bool read_file(Graph &graph)
{
	char path[1000];
	printf("Nhap vao duong dan: ");
	fgets(path, sizeof(path), stdin);
	//Xử lý dấu "" nếu có
	int j = 0;
	if (path[0] == '"' || path[(strcspn(path, "\n")) - 1] == '"')
	{
		for (int i = 1; i < strlen(path); i++)
		{
			if (path[i] == '\n')
			{
				path[j] = '\0';
				break;
			}
			if (path[i] == '"') continue;
			path[j++] = path[i];
		}
	}
	else
	{
		for (int i = 0; i < strlen(path); i++)
		{
			if (path[i] == '\n')
			{
				path[i] = '\0';
				break;
			}
			path[i] = path[i];
		}
	}
	FILE *file;
	fopen_s(&file, path, "r");
	if (file == NULL)
	{
		printf("Khong the mo file, kiem tra lai duong dan");
		return false;
	}

	// Bắt đầu xử lý chuỗi
	// Đọc line đầu và truyền vào tổng số đỉnh
	char line[1000];
	char *line_read = fgets(line, sizeof(line), file);
	graph.tongsodinh = atoi(line);
	
	// Đọc tiếp các line
	while (fgets(line, sizeof(line), file) != NULL)
	{
		read_line_create_graph(line, graph);
	}

	graph.in_dothi();

}

void read_line_create_graph(const char* line, Graph &graph)
{
	int i = 0;
	Vertex vertex;
	char dulieu[10];
	int index_ghi = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			i++;
			dulieu[index_ghi] = '\0';
			index_ghi = 0;
			vertex.dinhlienke.push_back(atoi(dulieu));
			continue;
		}
		dulieu[index_ghi++] = line[i++];
		if (line[i] == '\n' || line[i] == '\0')
		{
			vertex.dinhlienke.push_back(atoi(dulieu));
		}
	}
	graph.danhsachdinh.push_back(vertex);
}