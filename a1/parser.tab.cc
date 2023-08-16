// A Bison parser, made by GNU Bison 3.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 50 "parser.yy"

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <string>
   
   
   #include "scanner.hh"
   int nodeCount = 0;

#undef yylex
#define yylex IPL::Parser::scanner.yylex


#line 60 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy"
namespace IPL {
#line 152 "parser.tab.cc"


  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< int > (std::move (that.value));
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< int > (YY_MOVE (s.value));
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< int > (YY_MOVE (that.value));
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.copy< int > (that.value);
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< int > (that.value);
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 3: // STRING_LITERAL
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 806 "parser.tab.cc"
        break;

      case 4: // WHILE
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 812 "parser.tab.cc"
        break;

      case 5: // FOR
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 818 "parser.tab.cc"
        break;

      case 6: // STRUCT
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 824 "parser.tab.cc"
        break;

      case 7: // INT
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 830 "parser.tab.cc"
        break;

      case 8: // FLOAT
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 836 "parser.tab.cc"
        break;

      case 9: // VOID
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 842 "parser.tab.cc"
        break;

      case 10: // IF
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 848 "parser.tab.cc"
        break;

      case 11: // ELSE
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 854 "parser.tab.cc"
        break;

      case 12: // RETURN
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 860 "parser.tab.cc"
        break;

      case 13: // INC_OP
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 866 "parser.tab.cc"
        break;

      case 14: // OR_OP
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 872 "parser.tab.cc"
        break;

      case 15: // AND_OP
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 878 "parser.tab.cc"
        break;

      case 16: // PTR_OP
#line 38 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 884 "parser.tab.cc"
        break;

      case 17: // EQ_OP
#line 39 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 890 "parser.tab.cc"
        break;

      case 18: // NE_OP
#line 40 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 896 "parser.tab.cc"
        break;

      case 19: // LE_OP
#line 41 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 902 "parser.tab.cc"
        break;

      case 20: // GE_OP
#line 42 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 908 "parser.tab.cc"
        break;

      case 21: // INT_CONSTANT
#line 43 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 914 "parser.tab.cc"
        break;

      case 22: // FLOAT_CONSTANT
#line 44 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 920 "parser.tab.cc"
        break;

      case 23: // IDENTIFIER
#line 45 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 926 "parser.tab.cc"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", static_cast<state_type> (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 44: // translation_unit
      case 45: // struct_specifier
      case 46: // function_definition
      case 47: // type_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        yylhs.value.emplace< int > ();
        break;

      case 3: // STRING_LITERAL
      case 4: // WHILE
      case 5: // FOR
      case 6: // STRUCT
      case 7: // INT
      case 8: // FLOAT
      case 9: // VOID
      case 10: // IF
      case 11: // ELSE
      case 12: // RETURN
      case 13: // INC_OP
      case 14: // OR_OP
      case 15: // AND_OP
      case 16: // PTR_OP
      case 17: // EQ_OP
      case 18: // NE_OP
      case 19: // LE_OP
      case 20: // GE_OP
      case 21: // INT_CONSTANT
      case 22: // FLOAT_CONSTANT
      case 23: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 103 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"translation_unit\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1228 "parser.tab.cc"
    break;

  case 3:
#line 111 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"translation_unit\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1238 "parser.tab.cc"
    break;

  case 4:
#line 119 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"translation_unit\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1249 "parser.tab.cc"
    break;

  case 5:
#line 128 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"translation_unit\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1260 "parser.tab.cc"
    break;

  case 6:
#line 138 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"struct_specifier\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[5].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[4].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" { \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" } \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1280 "parser.tab.cc"
    break;

  case 7:
#line 157 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"function_definition\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1292 "parser.tab.cc"
    break;

  case 8:
#line 168 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"type_specifier\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[0].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1303 "parser.tab.cc"
    break;

  case 9:
#line 177 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"type_specifier\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[0].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1314 "parser.tab.cc"
    break;

  case 10:
#line 186 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"type_specifier\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[0].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1325 "parser.tab.cc"
    break;

  case 11:
#line 195 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"type_specifier\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1338 "parser.tab.cc"
    break;

  case 12:
#line 207 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"fun_declarator\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[3].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1354 "parser.tab.cc"
    break;

  case 13:
#line 221 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"fun_declarator\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[2].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1369 "parser.tab.cc"
    break;

  case 14:
#line 235 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"parameter_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1379 "parser.tab.cc"
    break;

  case 15:
#line 243 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"parameter_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\",\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1392 "parser.tab.cc"
    break;

  case 16:
#line 255 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"parameter_declaration\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1403 "parser.tab.cc"
    break;

  case 17:
#line 265 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declarator_arr\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1414 "parser.tab.cc"
    break;

  case 18:
#line 274 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declarator_arr\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[3].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" [ \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[1].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ] \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1430 "parser.tab.cc"
    break;

  case 19:
#line 289 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declarator\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1440 "parser.tab.cc"
    break;

  case 20:
#line 297 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declarator\"]\n";
		std::cout << ++nodeCount << "[label=\" * \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1452 "parser.tab.cc"
    break;

  case 21:
#line 308 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"compound_statement\"]\n";
		std::cout << ++nodeCount << "[label=\" { \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" } \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1465 "parser.tab.cc"
    break;

  case 22:
#line 319 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"compound_statement\"]\n";
		std::cout << ++nodeCount << "[label=\" { \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" } \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1479 "parser.tab.cc"
    break;

  case 23:
#line 331 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"compound_statement\"]\n";
		std::cout << ++nodeCount << "[label=\" { \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" } \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1494 "parser.tab.cc"
    break;

  case 24:
#line 345 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1504 "parser.tab.cc"
    break;

  case 25:
#line 353 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1515 "parser.tab.cc"
    break;

  case 26:
#line 363 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1526 "parser.tab.cc"
    break;

  case 27:
#line 372 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << ++nodeCount << "[label=\" { \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" } \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1540 "parser.tab.cc"
    break;

  case 28:
#line 384 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1550 "parser.tab.cc"
    break;

  case 29:
#line 392 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1560 "parser.tab.cc"
    break;

  case 30:
#line 400 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1570 "parser.tab.cc"
    break;

  case 31:
#line 408 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1580 "parser.tab.cc"
    break;

  case 32:
#line 416 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"statement\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[2].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1594 "parser.tab.cc"
    break;

  case 33:
#line 429 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"assignment_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" = \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1607 "parser.tab.cc"
    break;

  case 34:
#line 441 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"assignment_statement\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1619 "parser.tab.cc"
    break;

  case 35:
#line 452 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"procedure_call\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[3].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1636 "parser.tab.cc"
    break;

  case 36:
#line 467 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"procedure_call\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[4].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1654 "parser.tab.cc"
    break;

  case 37:
#line 484 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1664 "parser.tab.cc"
    break;

  case 38:
#line 492 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1677 "parser.tab.cc"
    break;

  case 39:
#line 504 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"logical_and_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1687 "parser.tab.cc"
    break;

  case 40:
#line 512 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"logical_and_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1700 "parser.tab.cc"
    break;

  case 41:
#line 525 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"equality_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1710 "parser.tab.cc"
    break;

  case 42:
#line 533 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"equality_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1723 "parser.tab.cc"
    break;

  case 43:
#line 544 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"equality_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1736 "parser.tab.cc"
    break;

  case 44:
#line 556 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"relational_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1746 "parser.tab.cc"
    break;

  case 45:
#line 564 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"relational_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" < \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1759 "parser.tab.cc"
    break;

  case 46:
#line 575 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"relational_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" > \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1772 "parser.tab.cc"
    break;

  case 47:
#line 586 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"relational_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1785 "parser.tab.cc"
    break;

  case 48:
#line 597 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"relational_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1798 "parser.tab.cc"
    break;

  case 49:
#line 609 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"additive_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1808 "parser.tab.cc"
    break;

  case 50:
#line 617 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"additive_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" + \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1821 "parser.tab.cc"
    break;

  case 51:
#line 628 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"additive_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" - \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1834 "parser.tab.cc"
    break;

  case 52:
#line 640 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"unary_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1844 "parser.tab.cc"
    break;

  case 53:
#line 648 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"unary_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1855 "parser.tab.cc"
    break;

  case 54:
#line 658 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"multiplicative_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1865 "parser.tab.cc"
    break;

  case 55:
#line 666 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"multiplicative_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" * \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1878 "parser.tab.cc"
    break;

  case 56:
#line 677 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"multiplicative_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" / \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1891 "parser.tab.cc"
    break;

  case 57:
#line 689 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 1901 "parser.tab.cc"
    break;

  case 58:
#line 697 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[3].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" [ \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ] \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1916 "parser.tab.cc"
    break;

  case 59:
#line 710 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[2].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1931 "parser.tab.cc"
    break;

  case 60:
#line 723 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[3].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1947 "parser.tab.cc"
    break;

  case 61:
#line 737 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" . \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1961 "parser.tab.cc"
    break;

  case 62:
#line 749 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1975 "parser.tab.cc"
    break;

  case 63:
#line 761 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"postfix_expression\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[0].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1987 "parser.tab.cc"
    break;

  case 64:
#line 772 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"primary_expression\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 1998 "parser.tab.cc"
    break;

  case 65:
#line 781 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"primary_expression\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2009 "parser.tab.cc"
    break;

  case 66:
#line 790 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"primary_expression\"]\n";
		std::cout << ++nodeCount << "[label=\"" << yystack_[0].value.as < std::string > () << "\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2020 "parser.tab.cc"
    break;

  case 67:
#line 799 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"primary_expression\"]\n";
		std::cout << ++nodeCount << "[label= \"\\\"\" + " << yystack_[0].value.as < std::string > () << " + \"\\\"\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2031 "parser.tab.cc"
    break;

  case 68:
#line 808 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"primary_expression\"]\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2045 "parser.tab.cc"
    break;

  case 69:
#line 821 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"expression_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2055 "parser.tab.cc"
    break;

  case 70:
#line 829 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"expression_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" , \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2068 "parser.tab.cc"
    break;

  case 71:
#line 841 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"unary_operator\"]\n";
		std::cout << ++nodeCount << "[label=\" - \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2079 "parser.tab.cc"
    break;

  case 72:
#line 850 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"unary_operator\"]\n";
		std::cout << ++nodeCount << "[label=\" ! \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2090 "parser.tab.cc"
    break;

  case 73:
#line 859 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"unary_operator\"]\n";
		std::cout << ++nodeCount << "[label=\" & \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2101 "parser.tab.cc"
    break;

  case 74:
#line 868 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"unary_operator\"]\n";
		std::cout << ++nodeCount << "[label=\" * \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2112 "parser.tab.cc"
    break;

  case 75:
#line 878 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"selection_statement\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[6].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[4].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[1].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2132 "parser.tab.cc"
    break;

  case 76:
#line 897 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"iteration_statement\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[4].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2149 "parser.tab.cc"
    break;

  case 77:
#line 912 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"iteration_statement\"]\n";
		std::cout << ++nodeCount << "[label=\" " << yystack_[8].value.as < std::string > () << " \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << ++nodeCount << "[label=\" ( \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[6].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[4].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ) \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2172 "parser.tab.cc"
    break;

  case 78:
#line 934 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declaration_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2182 "parser.tab.cc"
    break;

  case 79:
#line 942 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declaration_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2193 "parser.tab.cc"
    break;

  case 80:
#line 952 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declaration\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[1].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" ; \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
	}
#line 2206 "parser.tab.cc"
    break;

  case 81:
#line 964 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declarator_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2216 "parser.tab.cc"
    break;

  case 82:
#line 972 "parser.yy"
        {
		yylhs.value.as < int > () = ++nodeCount;
		std::cout << yylhs.value.as < int > () << "[label=\"declarator_list\"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[2].value.as < int > () << "\n";
		std::cout << ++nodeCount << "[label=\" , \"]\n";
		std::cout << yylhs.value.as < int > () << " -> " << nodeCount << "\n";
		std::cout << yylhs.value.as < int > () << " -> " << yystack_[0].value.as < int > () << "\n";
	}
#line 2229 "parser.tab.cc"
    break;


#line 2233 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = static_cast<state_type> (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -80;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     112,    32,   -80,   -80,   -80,   169,   -80,   -80,    45,    51,
     -80,   -80,   -80,    56,    59,   165,    21,   120,   -80,    70,
      36,     6,   -80,   -80,    36,    30,   -80,   -80,    77,    80,
      84,   302,   -80,   -80,    95,   -80,   302,    42,   -80,   -80,
     -80,   -80,   -80,   196,   -80,   110,   -80,   -80,    94,    -9,
     -80,   302,   -80,   -80,   158,   -80,   -80,    36,   108,   -80,
     107,   114,   -80,   -80,   165,   -80,   302,   302,   302,   118,
      29,   131,    -1,    54,   -16,   -80,    67,    75,    63,   234,
     -80,   -80,   -80,   302,   -80,   129,   302,   132,   -80,   272,
     -80,   127,   -80,    36,   -80,   -80,    71,   159,    78,   294,
     302,   -80,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   160,   172,   125,   -80,   -80,   172,   -80,
       9,   -80,   -80,   161,   -80,    42,   302,    42,   -80,   130,
     131,    -1,    54,    54,   -16,   -16,   -16,   -16,    67,    67,
     -80,   -80,   -80,   302,   170,   -80,   -80,   -80,    37,   185,
     -80,   172,   -80,   302,    42,   174,   -80,    42,   -80
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     9,    10,     8,     0,     2,     3,     0,    11,
       1,     4,     5,     0,     0,     0,     0,     0,     7,     0,
       0,     0,    78,    13,     0,     0,    14,    67,     0,     0,
       0,     0,    65,    66,    64,    26,     0,     0,    21,    74,
      71,    72,    73,     0,    24,     0,    30,    31,     0,    52,
      57,     0,    28,    29,     0,    11,    17,     0,    19,    81,
       0,     0,    79,    16,     0,    12,     0,     0,     0,    64,
       0,    37,    39,    41,    44,    54,    49,     0,     0,     0,
      22,    25,    34,     0,    63,     0,     0,     0,    53,     0,
      20,     0,    80,     0,     6,    15,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    69,     0,    68,    27,    33,    62,
       0,    61,    23,     0,    82,     0,     0,     0,    59,     0,
      38,    40,    42,    43,    47,    48,    45,    46,    50,    51,
      55,    56,    35,     0,    60,    58,    18,    76,     0,     0,
      60,    70,    36,     0,     0,     0,    75,     0,    77
  };

  const short
  Parser::yypgoto_[] =
  {
     -80,   -80,   198,   199,     3,   -80,   -80,   141,   -80,   -18,
     -80,   -19,   -41,   -66,   -80,   -80,   -26,   109,   105,   -79,
      83,   -17,   -78,   -80,   -80,   111,   -80,   -80,   -80,   194,
     -10,   -80
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,    20,    14,    25,    26,    58,    59,
      18,    43,    44,    45,    46,    47,   114,    71,    72,    73,
      74,    75,    76,    49,    50,   115,    51,    52,    53,    21,
      22,    60
  };

  const unsigned char
  Parser::yytable_[] =
  {
      48,    97,    81,     8,    84,    70,    63,    85,     8,   109,
      78,    62,    19,     2,     3,     4,   103,   104,    79,    24,
      48,   110,    86,   100,   132,   133,    48,    19,     2,     3,
       4,   138,   139,    87,    88,    89,    61,    48,    81,    90,
      96,   145,    98,   100,    62,    27,    28,    29,    81,    23,
      48,   100,    30,   101,    31,     9,    64,   118,    65,    56,
     120,   153,    48,    32,    33,    34,    35,    24,    13,    36,
      57,    37,    48,   105,   106,   124,    39,   100,    27,    40,
      15,    41,    42,    16,   147,   100,   149,   155,    17,   107,
     108,   116,   100,    55,   140,   141,    32,    33,    69,   125,
     148,   111,    36,   113,    66,   112,   127,    67,    48,    39,
      48,    68,    40,   156,    41,    42,   158,   151,     1,     2,
       3,     4,    77,    27,    28,    29,    19,     2,     3,     4,
      30,    92,    31,    93,    82,    83,    48,    48,    94,    91,
      48,    32,    33,    34,    35,    99,   102,    36,   123,    37,
      38,   143,   119,   144,    39,   121,   143,    40,   150,    41,
      42,    27,    28,    29,    19,     2,     3,     4,    30,    10,
      31,    19,     2,     3,     4,     1,     2,     3,     4,    32,
      33,    34,    35,   126,   142,    36,   100,    37,   134,   135,
     136,   137,    39,   146,   152,    40,   154,    41,    42,    27,
      28,    29,   157,    11,    12,    95,    30,   131,    31,   130,
     129,    54,     0,     0,     0,     0,     0,    32,    33,    34,
      35,     0,     0,    36,     0,    37,    80,     0,     0,     0,
      39,     0,     0,    40,     0,    41,    42,    27,    28,    29,
       0,     0,     0,     0,    30,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,    34,    35,     0,
       0,    36,     0,    37,   117,     0,     0,     0,    39,     0,
       0,    40,     0,    41,    42,    27,    28,    29,     0,     0,
       0,     0,    30,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,    27,     0,    36,
       0,    37,   122,     0,     0,    27,    39,     0,     0,    40,
       0,    41,    42,     0,     0,    32,    33,    69,     0,     0,
       0,    36,   128,    32,    33,    69,     0,     0,    39,    36,
       0,    40,     0,    41,    42,     0,    39,     0,     0,    40,
       0,    41,    42
  };

  const short
  Parser::yycheck_[] =
  {
      17,    67,    43,     0,    13,    31,    24,    16,     5,    25,
      36,    21,     6,     7,     8,     9,    17,    18,    37,    16,
      37,    37,    31,    14,   103,   104,    43,     6,     7,     8,
       9,   109,   110,    42,    51,    54,    30,    54,    79,    57,
      66,    32,    68,    14,    54,     3,     4,     5,    89,    28,
      67,    14,    10,    24,    12,    23,    26,    83,    28,    23,
      86,    24,    79,    21,    22,    23,    24,    64,    23,    27,
      34,    29,    89,    19,    20,    93,    34,    14,     3,    37,
      29,    39,    40,    27,   125,    14,   127,   153,    29,    35,
      36,    28,    14,    23,   111,   112,    21,    22,    23,    28,
     126,    34,    27,    28,    27,    38,    28,    27,   125,    34,
     127,    27,    37,   154,    39,    40,   157,   143,     6,     7,
       8,     9,    27,     3,     4,     5,     6,     7,     8,     9,
      10,    24,    12,    26,    24,    41,   153,   154,    24,    31,
     157,    21,    22,    23,    24,    27,    15,    27,    21,    29,
      30,    26,    23,    28,    34,    23,    26,    37,    28,    39,
      40,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      12,     6,     7,     8,     9,     6,     7,     8,     9,    21,
      22,    23,    24,    24,    24,    27,    14,    29,   105,   106,
     107,   108,    34,    32,    24,    37,    11,    39,    40,     3,
       4,     5,    28,     5,     5,    64,    10,   102,    12,   100,
      99,    17,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    39,    40,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    34,    -1,
      -1,    37,    -1,    39,    40,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,     3,    -1,    27,
      -1,    29,    30,    -1,    -1,     3,    34,    -1,    -1,    37,
      -1,    39,    40,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    21,    22,    23,    -1,    -1,    34,    27,
      -1,    37,    -1,    39,    40,    -1,    34,    -1,    -1,    37,
      -1,    39,    40
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     6,     7,     8,     9,    44,    45,    46,    47,    23,
       0,    45,    46,    23,    48,    29,    27,    29,    53,     6,
      47,    72,    73,    28,    47,    49,    50,     3,     4,     5,
      10,    12,    21,    22,    23,    24,    27,    29,    30,    34,
      37,    39,    40,    54,    55,    56,    57,    58,    64,    66,
      67,    69,    70,    71,    72,    23,    23,    34,    51,    52,
      74,    30,    73,    52,    26,    28,    27,    27,    27,    23,
      59,    60,    61,    62,    63,    64,    65,    27,    59,    54,
      30,    55,    24,    41,    13,    16,    31,    42,    64,    54,
      52,    31,    24,    26,    24,    50,    59,    56,    59,    27,
      14,    24,    15,    17,    18,    19,    20,    35,    36,    25,
      37,    34,    38,    28,    59,    68,    28,    30,    59,    23,
      59,    23,    30,    21,    52,    28,    24,    28,    28,    68,
      60,    61,    62,    62,    63,    63,    63,    63,    65,    65,
      64,    64,    24,    26,    28,    32,    32,    55,    59,    55,
      28,    59,    24,    24,    11,    56,    55,    28,    55
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    43,    44,    44,    44,    44,    45,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    56,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    71,    71,    72,    72,
      73,    74,    74
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     6,     3,     1,     1,
       1,     2,     4,     3,     1,     3,     2,     1,     4,     1,
       2,     2,     3,     4,     1,     2,     1,     3,     1,     1,
       1,     1,     3,     3,     2,     4,     5,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     2,     1,     3,     3,     1,     4,     3,
       4,     3,     3,     2,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     7,     5,     9,     1,     2,
       3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "STRING_LITERAL", "WHILE", "FOR",
  "STRUCT", "INT", "FLOAT", "VOID", "IF", "ELSE", "RETURN", "INC_OP",
  "OR_OP", "AND_OP", "PTR_OP", "EQ_OP", "NE_OP", "LE_OP", "GE_OP",
  "INT_CONSTANT", "FLOAT_CONSTANT", "IDENTIFIER", "';'", "'+'", "','",
  "'('", "')'", "'{'", "'}'", "'['", "']'", "':'", "'*'", "'<'", "'>'",
  "'-'", "'/'", "'!'", "'&'", "'='", "'.'", "$accept", "translation_unit",
  "struct_specifier", "function_definition", "type_specifier",
  "fun_declarator", "parameter_list", "parameter_declaration",
  "declarator_arr", "declarator", "compound_statement", "statement_list",
  "statement", "assignment_expression", "assignment_statement",
  "procedure_call", "expression", "logical_and_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "unary_expression", "multiplicative_expression", "postfix_expression",
  "primary_expression", "expression_list", "unary_operator",
  "selection_statement", "iteration_statement", "declaration_list",
  "declaration", "declarator_list", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   102,   102,   110,   118,   127,   137,   156,   167,   176,
     185,   194,   206,   220,   234,   242,   254,   264,   273,   288,
     296,   307,   318,   330,   344,   352,   362,   371,   383,   391,
     399,   407,   415,   428,   440,   451,   466,   483,   491,   503,
     511,   524,   532,   543,   555,   563,   574,   585,   596,   608,
     616,   627,   639,   647,   657,   665,   676,   688,   696,   709,
     722,   736,   748,   760,   771,   780,   789,   798,   807,   820,
     828,   840,   849,   858,   867,   877,   896,   911,   933,   941,
     951,   963,   971
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,    40,     2,
      27,    28,    34,    25,    26,    37,    42,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    24,
      35,    41,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
    };
    const int user_token_number_max_ = 278;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "parser.yy"
} // IPL
#line 2726 "parser.tab.cc"

#line 984 "parser.yy"

void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}


