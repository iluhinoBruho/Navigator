#include "Logics.h"

std::vector<std::string> get_way(const Matrix& graph, std::string s, std::string f)
{
    int start = graph.get_num(s);
    int finish = graph.get_num(f);
    std::cout << start << " " << finish << " <START I FINISH" << std::endl;
    std::vector<int> int_path = Dejikstra(graph.data(), start, finish);
    std::vector<std::string> str_path;
    for(auto el : int_path)
        str_path.push_back(graph.get_name(el));
    return str_path;
}

std::vector<int> Dejikstra(const table& g, int start, int finish)
{
    int n = g.size();
    std::vector<int> dist (n, INF);
    std::vector<int> prev(n);
    dist[start] = 0;
    std::vector<char> visited(n);

    for (int i = 0; i < n; ++i)
    {
        int v = -1; // v-vertex
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (visited[v] == INF)
            break;
        visited[v] = true;

        for (int j = 0; j < g[v].size(); ++j)
        {
            int to = j; // j is vertex which we try to relax
            int len = g[v][j]; //lenght of edge from choosen vertex v to vertex j
            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                prev[to] = v;
            }
        }
    }



    std::vector<int> path;
    if(dist[finish] == INF)
    {
        std::cout << "NO WAY" << std::endl;
        return path;
    }
    for (int vertex = finish; vertex != start; vertex = prev[vertex])
        path.push_back (vertex);
    path.push_back (start);
    std::reverse (path.begin(), path.end());
    return path;
}
