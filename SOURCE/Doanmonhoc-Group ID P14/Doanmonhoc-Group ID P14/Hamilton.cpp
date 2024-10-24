#include <vector>
#include "header.h"
#include "Hamilton.h"

void run(Graph &graph, std::vector<int> temp_path, int curr_, std::vector<int> &path, int* result, int start)
{
    // 1 or 2
    if (temp_path.size() == graph.danhsachdinh.size())
    {
        bool chu_trinh = false;
        for (int i = 0; i < graph.danhsachdinh[curr_].dinhlienke.size(); i++)
        {
            int next = graph.danhsachdinh[curr_].dinhlienke[i];
            if (next == start)
            {
                *result = 2;
                path = temp_path;
                path.push_back(start);
                chu_trinh = true;
                return ;
            }
        }
        if(chu_trinh == false)
        {
            *result = 1;
            path = temp_path;
            return ;
        }
    }
    else
    {
        for (int i = 0; i < graph.danhsachdinh[curr_].dinhlienke.size(); i++)
        {
            int next = graph.danhsachdinh[curr_].dinhlienke[i];
            if (graph.danhsachdinh[next].passed == false)
            {
                graph.danhsachdinh[next].passed = true;
                temp_path.push_back(next);

                run(graph, temp_path, next, path, result, start);
                if(*result==2)
                {
                    return;
                    break;
                }

                graph.danhsachdinh[next].passed = false;
                temp_path.pop_back();
            }
        }
    }
}

int Hamilton(Graph &graph, std::vector<int> &duongdi, int dinhbatdau)
{
    // start
    graph.danhsachdinh[dinhbatdau].passed = true;
    duongdi.push_back(dinhbatdau);
    int* res;
    res = (int *)malloc(sizeof(int));
    *res = 0;
    std::vector<int> temp_duongdi;
    temp_duongdi.push_back(dinhbatdau);

    // first step
    run(graph, temp_duongdi, dinhbatdau, duongdi, res, dinhbatdau);

    return *res;
};
