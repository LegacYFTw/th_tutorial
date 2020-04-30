#include <bits/stdc++.h>

using namespace std;

set<string> vertices;
set<pair<string, string> > edges;

void add_edge(const string& vertex1, const string& vertex2)
{
    if(vertex1 < vertex2)
    {
        edges.insert(make_pair(vertex1, vertex2));
    }
    else
    {
        edges.insert(make_pair(vertex2, vertex1));
    }
}

void dfs(string& base)
{
    if(vertices.find(base) != vertices.end())
    {
        return;
    }
    vertices.insert(base);

    constexpr int MAX{numeric_limits<int>::max()};
    array<int, 3> towers;
    fill(towers.begin(), towers.end(), MAX);
    const int N(base.size());

    for(int disk_number = 0; disk_number < N; ++disk_number)
    {
        const int pos{base[disk_number] - 'A'};
        towers[pos] = min(towers[pos], disk_number);
    }

    for(const auto disk_number : towers)
    {
        if(disk_number != MAX)
        {
            string temp{base};
            const char prev{temp[disk_number]};
            for(const auto pos : {0, 1, 2})
            {
                if(disk_number < towers[pos])
                {
                    temp[disk_number] = char('A' + pos);
                    add_edge(base, temp);
                    dfs(temp);
                    temp[disk_number] = prev;
                }
            }
        }
    }
}

void generate(const int N)
{
    string base(N, 'A');
    dfs(base);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);

    int N;
    if(argc == 2)
    {
        N = atoi(argv[1]);
    }
    else
    {
        cout << "Number of disks: ";
        cin >> N;
    }

    generate(N);

    ofstream file;
    file.open("edge_list.txt");
    file << edges.size() << endl;
    for(const auto& edge : edges)
    {
        file << edge.first << " " << edge.second << endl;
    }
    file.close();

    return 0;
}
