#include "Shader.h"



Shader::Shader(const GLchar * vertex_file_path, const GLchar * fragment_file_path)
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);



	//Read vertex shader code from file
	std::string vertex_path = __FILE__; //gets source code path, include file name
	vertex_path = vertex_path.substr(0, 1 + vertex_path.find_last_of('\\')); //removes file name
	vertex_path += vertex_file_path; //adds input file to path

	std::ifstream ifs(vertex_path);

	if (!ifs.is_open()) {

		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return;
	}

	std::string VertexShaderCode((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));









	//Read fragment Shader code from file
	std::string fragment_path = __FILE__; //gets source code path, include file name
	fragment_path = fragment_path.substr(0, 1 + fragment_path.find_last_of('\\')); //removes file name
	fragment_path += fragment_file_path; //adds input file to path

	std::ifstream iffs(fragment_path);

	if (!iffs.is_open()) {

		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return;

	}

	std::string FragmentShaderCode((std::istreambuf_iterator<char>(iffs)),
		(std::istreambuf_iterator<char>()));




	program = glCreateProgram();
	unsigned int vs = this->CompileShader(GL_VERTEX_SHADER, VertexShaderCode);
	unsigned int fs = this->CompileShader(GL_FRAGMENT_SHADER, FragmentShaderCode);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

}






unsigned int Shader::CompileShader(unsigned int type, const std::string &source) {
	unsigned int id = glCreateShader(type);
	const char *src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);


	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	

	//error handling
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char *)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}





void Shader::use() {
	glUseProgram(program);
}
// utility uniform functions
void Shader::setBool(const std::string &name, bool value) const {
	glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value);
}


void Shader::setInt(const std::string &name, int value) const {
	glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}


void Shader::setFloat(const std::string &name, float value) const {
	glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}




Shader::~Shader()
{
}
