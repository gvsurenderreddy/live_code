#ifndef _GLSLPROGRAM_H
#define _GLSLPROGRAM_H

#include <glm/glm.hpp>
#include "gl_core_3_3.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::mat3;

class GLSLProgram
{
	private:
		int  handle;
		bool linked;

		int  getUniformLocation(const char * name );

	public:
		GLSLProgram() { handle=-1; linked = false;};
		GLSLProgram( const GLSLProgram &c) {
		       	handle = c.handle;
		       	linked = c.linked;};
		GLSLProgram & operator= (const GLSLProgram &c) {
		       	handle = c.handle;
		       	linked = c.linked;
			return *this;
		};


		void   use();

		int    getHandle();
		void   setHandle(int _handle) {handle = _handle;};

		void   bindAttribLocation( GLuint location, const char * name);
		void   bindFragDataLocation( GLuint location, const char * name );

		void   setUniform( const char *name, float x, float y, float z);
		void   setUniform( const char *name, const vec3 & v);
		void   setUniform( const char *name, const vec4 & v);
		void   setUniform( const char *name, const mat4 & m);
		void   setUniform( const char *name, const mat3 & m);
		void   setUniform( const char *name, float val );
		void   setUniform( const char *name, int val );
		void   setUniform( const char *name, bool val );

		void   printActiveUniforms();
		void   printActiveAttribs();
};

#endif // GLSLPROGRAM_H
