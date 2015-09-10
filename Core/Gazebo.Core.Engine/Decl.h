#pragma once

#ifdef EXPORT
#define DECL __declspec(dllexport)
#elif IMPORT
#define DECL __declspec(dllimport)
#else
#define DECL
#endif /* EXPORT */
