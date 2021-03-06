// MIT License
//
// Simple compiler front-end for LLVM written as a learning exercise.
// Copyright © 2017 Alberto Taiuti
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef BRT_VISITOR_HPP
#define BRT_VISITOR_HPP

#include <string>
#include <map>
#include <variant>
#include <memory>
#include <ast_types.hpp>
#include <llvm/IR/Type.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>

// Forward declarations
namespace brt {

struct Compiler;

} // namespace brt

namespace brt {

/// Visitor which consumes expression nodes
class ExprVisitor {
 public:
  ExprVisitor(std::shared_ptr<Compiler> compiler);

  llvm::Value *operator()(std::nullptr_t &arg);
  llvm::Value *operator()(NumLitExprAST &arg);
  llvm::Value *operator()(VarExprAST &arg);
  llvm::Value *operator()(BinExprAST &arg);
  llvm::Value *operator()(CallExprAST &arg);
  llvm::Value *operator()(IfExprAST &arg);
  llvm::Value *operator()(ForExprAST &arg);

 private:
  std::shared_ptr<Compiler> c_;

}; // class ExprVisitor

/// Visitor which consumes function nodes
class FuncVisitor {
 public:
  FuncVisitor(std::shared_ptr<Compiler> compiler);

  llvm::Function *operator()(std::nullptr_t &arg);
  llvm::Function *operator()(ProtoAST &arg);
  llvm::Function *operator()(FuncAST &arg);

 private:
  std::shared_ptr<Compiler> c_;

}; // class FuncVisitor

} // namespace brt

#endif
