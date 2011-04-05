#ifndef CONSOLE_OUTPUT_DEFINED
#define CONSOLE_OUTPUT_DEFINED

#include "../core/datatypes.h"

using namespace std;

struct Console_Output : public Error_Output
{
  Console_Output(uint log_level_) : encoding_errors(false), parse_errors(false),
  static_errors(false), log_level(log_level_) {}
  
  virtual void add_encoding_error(const string& error);
  virtual void add_parse_error(const string& error, int line_number);
  virtual void add_static_error(const string& error, int line_number);
  
  virtual void add_encoding_remark(const string& error);
  virtual void add_parse_remark(const string& error, int line_number);
  virtual void add_static_remark(const string& error, int line_number);
  
  virtual void runtime_error(const string& error);
  virtual void runtime_remark(const string& error);
  virtual void display_statement_stopwatch
    (const string& name,
     const vector< double >& stopwatches,
     const vector< uint >& read_counts);
  
  virtual bool display_encoding_errors() { return encoding_errors; }
  virtual bool display_parse_errors() { return parse_errors; }
  virtual bool display_static_errors() { return static_errors; }
  
private:
  bool encoding_errors;
  bool parse_errors;
  bool static_errors;
  uint log_level;
};

#endif
