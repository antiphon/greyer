#include <vector>
#include "Pplite.h"
#include "Node.h"

#ifndef G_H_
#define G_H_

class Graphnested {
  std::vector<std::vector<Node *> > nodes;
  std::vector<double> r; // increasing range vector for geometric graph
  std::vector<int> last_points_max_range_neighbours;
  Pplite *x;
  std::vector<double > pars_d;
  std::vector<int > pars_i;
  bool is_empty;
  bool (Graphnested::*pair_suitable_pt)(int, int);

  double maxR;

  public:
    Graphnested(Pplite *x, std::vector<double> r);

  virtual ~Graphnested();
  void compute_edges();
  void update_edges_after_addition(); // after a point has been added
  void update_edges_after_addition_stored(); // after a point has been added, in case potential engibhours stored
  void update_edges_after_move(int *i);  // after a point has been moved
  void update_edges_after_delete(int *i); // after deletion of a point

  // special case: change the mark of last added point. good for off-data papangelou computing.
  void store_last_points_potential_neighbours();
  void set_last_points_potential_neighbours(std::vector<int> these);
  void update_edges_after_mark_change(); // the last points mark is changed.


  int neighbour_count_of_i_in_graph_k(int k, int i);
  int has_neighbours_i_in_graph_k(int k, int i);
  int neighbour_count_of_neighbour_j_of_i_in_graph_k(int k, int i, int j);

  void set_pars_i(std::vector<int >);
  void set_pars_d(std::vector<double >);

  bool suitable_mark(int); // test mark(i) in pars_i

  // criteria based on marks
  void set_pair_suitable_method(bool (Graphnested::*p)(int, int) );

  bool pair_suitable(int,int); // main call
  bool pair_suitable_no_marks(int,int);
  bool pair_suitable_same_mark(int,int);
  bool pair_suitable_same_mark_but_of_given_set(int, int); // neeed pars_i
  bool pair_suitable_different_mark(int,int);
  bool pair_suitable_different_mark_but_of_given_set(int, int); // neeed pars_i
};

#endif
