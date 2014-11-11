/*
 * This file reads reference genome and stores in a Genome data
 * structure. All the characters in genome are transfered to capital
 * letters, and Ns in the genome are randomly transfered to A, C, G
 * or T. For mapping bisulfite seqeunces, Cs in the genome are transfered
 * to T.
 * */

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include "util.hpp"

#include <vector>
#include <string>

using std::string;
using std::vector;

typedef struct {
  uint16_t num_of_chroms;
  vector<uint32_t> chrom_sizes;
  vector<uint32_t> chrom_start_pos;
  vector<string> chrom_names;
  uint32_t all_chroms_len;
  char* chrom_seqs;
} Genome;

class ReadGenome {
 public:
  ReadGenome(const string& chrom_file, Genome* _genome)
      : genome(_genome) {
    IdentifyChromosomes(chrom_file);
    ReadChromosomes();
  }
  ~ReadGenome() {
    free(genome->chrom_seqs);
  }

 private:
  /* indentify the chromosome files */
  void IdentifyChromosomes(const string& chrom_file);

  /*read chromosome sequences from all the chromosome files */
  void ReadChromosomes();

  /* transfer all the characters to capital letter */
  void ToCapital();

  /* all Ns in genome are randomly transfered to A, C, G or T*/
  void N2ACGT();

  /* For mapping bisulfite sequences, all Cs in genome are
   * transfered to T */
  void C2T();

  /* chromosome files */
  vector<string> chrom_files;

  Genome* genome;
};

#endif /* REFERENCE_H_ */
