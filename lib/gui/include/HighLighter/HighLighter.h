//===- HighLighter.h - ART-GUI HighLighter----------------------*- C++ -*-===//
//
//                     ANDROID REVERSE TOOLKIT
//
// This file is distributed under the GNU GENERAL PUBLIC LICENSE
// V3 License. See LICENSE.TXT for details.
//
//===---------------------------------------------------------------------===//
//
// HighLighter will highlight file opened in editor
//
//===----------------------------------------------------------------------===//

#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>

QSyntaxHighlighter *setHighLighter (QTextDocument *parent,QString fileName);
#endif // HIGHLIGHTER_H