#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>

#define DEFAULT_WEIGHT 1

template <typename T>
class Graph{
private:
    std::unordered_map<uint_fast64_t,
            std::pair<uint_fast64_t,
                    std::unordered_map<uint_fast64_t,
                            std::unordered_map<T, uint_fast64_t>>>> Gr;

    std::unordered_map<uint_fast64_t, bool> tempMarked;

    //map<int, pair<int, unordered_map<int, unordered_map<T, int>>>> Gr;
public:
    void Adjacency_matrix_print (std::string Filename, uint_fast64_t maxV, bool Weighted){
        std::ofstream o;
        o.open(Filename);
        //std::cout << Gr.size();
        if (Weighted){

        }
        else{
            //std::cout << "MaxV = " << maxV << "\n";

            for (int i = 1; i <= maxV; i++){
                for (int j = 1; j <= maxV; j++){
                    o << Gr[i].second[j][(T) 1];
                    if (j != maxV) o << " ";

                    //std::cout << Gr[i].second[j][(T) 1] << "(" << i << ";" << j << ")";
                    //if (j != maxV - 1) std::cout << " ";
                }
                if (i != maxV) o << "\n";
                //if (i != maxV) std::cout << "\n";
            }
            o.close();
        }
    }

    void Adjacency_matrix_print (std::string Filename, uint_fast64_t maxV){
        std::ofstream o;
        o.open(Filename);
        //std::cout << Gr.size();
        //std::cout << "MaxV = " << maxV << "\n";
        for (int i = 1; i <= maxV; i++){
            for (int j = 1; j <= maxV; j++){
                o << Gr[i].second[j][(T) DEFAULT_WEIGHT];
                if (j != maxV) o << " ";

                //std::cout << Gr[i].second[j][(T) 1] << "(" << i << ";" << j << ")";
                //if (j != maxV - 1) std::cout << " ";
            }
            if (i != maxV) o << "\n";
            //if (i != maxV) std::cout << "\n";
        }
        o.close();
    }

    void SetEdges(uint_fast64_t First_Vertex, uint_fast64_t Second_Vertex, T Weight, bool Direction){
        if (Direction){
            Gr[First_Vertex].second[Second_Vertex][Weight] += 1;
            Gr[First_Vertex].first += 1;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted\n";
        }
        else{
            Gr[First_Vertex].second[Second_Vertex][Weight] += 1;
            Gr[First_Vertex].first += 1;
            Gr[Second_Vertex].second[First_Vertex][Weight] += 1;
            Gr[Second_Vertex].first += 1;

            //std::cout << Gr[1].second[2][(T) 1] << "(" << 1 << ";" << 2 << ")";
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
            //std::cout << "\n" << Second_Vertex << ";" << First_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";

//            std::cout << "\n" << First_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
//            std::cout << "\n" << Second_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";
        }
    }

    void SetEdges(uint_fast64_t First_Vertex, uint_fast64_t Second_Vertex, bool Direction){
        if (Direction){
            Gr[First_Vertex].second[Second_Vertex][(T) DEFAULT_WEIGHT] += 1;
            Gr[First_Vertex].first += 1;
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted\n";
        }
        else{
            Gr[First_Vertex].second[Second_Vertex][(T) DEFAULT_WEIGHT] += 1;
            Gr[First_Vertex].first += 1;
            Gr[Second_Vertex].second[First_Vertex][(T) DEFAULT_WEIGHT] += 1;
            Gr[Second_Vertex].first += 1;

            //std::cout << Gr[1].second[2][(T) 1] << "(" << 1 << ";" << 2 << ")";
            //std::cout << "\n" << First_Vertex << ";" << Second_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
            //std::cout << "\n" << Second_Vertex << ";" << First_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";

//            std::cout << "\n" << First_Vertex << " Setted: "<< Gr[First_Vertex].first.second << "";
//            std::cout << "\n" << Second_Vertex << " Setted: "<< Gr[Second_Vertex].first.second << "\n";
        }
    }

    void Vertexes_degree(std::string Filename){
        std::ofstream o;
        std::vector<uint_fast64_t> temp;
        o.open(Filename);
        for (auto& i : Gr) {temp.push_back(i.first);}

        std::sort(temp.begin(), temp.end());

        for (auto& i : temp){
            o << i << " " << Gr[i].first<< "\n";
        }

        o.close();
    }

    void Double_directions(){
        for (const auto& i : Gr){
            for (const auto& j : i.second.second){
                for (const auto& k : j.second){
                    if (Gr[i.first].second[j.first][k.first] > 0) Gr[j.first].second[i.first][k.first] = Gr[i.first].second[j.first][k.first];
                }
            }
        }
    }

    bool Is_connected(uint_fast64_t first, uint_fast64_t last){
        if (first == last){
            return true;
        }
        tempMarked[first] = true;
        for (const auto& i : Gr[first].second){
                if (!tempMarked[i.first]){
                    if (this->Is_connected(i.first, last)) {
                        //tempMarked[i.first] = true;
                        return true;
                    }
                }
        }
        return false;
    }

    void Dijkstra_Shortest_path(uint_fast64_t first, uint_fast64_t last, std::string Filename, bool Direction, uint_fast64_t Vertexes, int Task) {
        T tempW = -1;
        std::vector<uint_fast64_t> path;
        std::unordered_map<uint_fast64_t, T> tempWeights;

        for (uint_fast64_t i = 1; i <= Vertexes; i++) {
            tempWeights[i] = std::numeric_limits<T>::max();
            tempMarked[i] = false;
        }
        //if (this->Is_connected(first, last)) {
        //    std::cout << this->Is_connected(first, last);

            uint_fast64_t min_not_marked = first;
            T min_weight = std::numeric_limits<T>::max();




            //for (const auto& i : Gr)

            tempWeights[first] = 0;
            while (!tempMarked[last]) {
//                for (uint_fast64_t i = 1; i <= Vertexes; i++) {
//                    std::cout << i << " " << tempWeights[i] << " " << tempMarked[i] << "\n";
//                }
//                std::cout << "-------------------------------------------------------------------\n";
                min_weight = std::numeric_limits<T>::max();
                for (const auto &j : tempMarked) {
                    if (j.second == false && min_weight > tempWeights[j.first]) {
                        min_weight = tempWeights[j.first];
                        min_not_marked = j.first;
                    }
                }
                for (const auto &j : Gr[min_not_marked].second) {
                    for (const auto &k : j.second) {
                        if (tempWeights[j.first] > tempWeights[min_not_marked] + k.first &&
                            tempMarked[j.first] == false)
                            tempWeights[j.first] = tempWeights[min_not_marked] + k.first;
                    }
                }
                tempMarked[min_not_marked] = true;
            }
//        for (const auto& i : Gr){
//            std::cout << i.first << " " << tempWeights[i.first] <<  " " << tempMarked[i.first] << "\n";
//        }


            min_weight = tempWeights[last];
            bool check = 0;
            uint_fast64_t second = first;
            uint_fast64_t current = last;
            tempW = 0;
            //std::cout << tempWeights[last];
            if (Direction) this->Double_directions();

            path.push_back(last);

            while (current != first) {
                //std::cout<< current << std::endl;
                for (const auto &i : Gr[current].second) {

                    for (const auto &j : i.second) {

                        //std::cout << current << " " << min_weight << " " << j.first << " " << tempWeights[i.first] << "\n";
                        if (min_weight - j.first == tempWeights[i.first]) {
                            min_weight -= j.first;
                            tempW += j.first;
                            path.push_back(i.first);
                            current = i.first;

                            break;
                        }
                    }
                }
            }
            //path.push_back(first);
            //if (tempW == 0) tempW = -1;

       // }

        std::ofstream file;
        file.open(Filename);
        if (Task == 4){
            file << tempW;
        }
        if (Task == 3){
            file << tempW << "\n";
            if (tempW != -1) {
                for (int i = path.size() - 1; i >= 0; i--) {
                    file << path[i];
                    if (i != 0) file << " ";
                }
            }
        }
        file.close();
    }


};
