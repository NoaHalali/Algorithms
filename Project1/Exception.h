#ifndef __EXCEPTION_H
#define __EXCEPTION_H


class Exception {};

class InvalidVertexException : public Exception {};

class InvalidEdgeException : public Exception{};

class InvalidGraphSizeException : public Exception {};



#endif