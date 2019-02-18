-----------------To run this project------------------    
Setting up visual studio  
	1. Open up visual studio. I am using visual studio 2017 community edition  
	2. Create an empty VC++ project.  
	3. create a src folder and within the src folder create main file.  
	4. write sample program to print hellow world in main file, if it runs you are good to go.  
	
	
Setting up dependencies  
	3. Download glfw from here https://www.glfw.org/download.html  download 32-bit windows binaries for simplicity.  
	4. Extract it somewhere.    
	5. Download glew from here http://glew.sourceforge.net/ download windows 32-bit binaries.    
	6. Extract it somewhere.  
	7. Go to visual studio project directory where sln file lives.  
	8. Create Dependencies folder to place your libraries. I recommend to create directories GLFW and GLEW within the dependencies folder.  
	9. In GLFW folder add include and lib-vc2015 folder from downloaded glfw folder in above step.  
	10.DO the same to GLEW folder. In instead of lib-vc2015 you might have just lib folder.  
	11.Now go to visual studio.  
	12.Open solution explorer.  
	13.right click on project folder. Go to properties.  
	14.go to c/c++ -> General -> Additional Include directories -> edit.  
	15.Add new line. In new line type $(SolutionDir)Dependencies\GLFW\include  
	16.Add another new line and type $(SolutionDir)Dependencies\GLEW\include  
	17.Go back to C/C++ -> Preprocessor -> preprocessor definitions and edit to inclue this GLEW_STATIC;_MBCS;%(PreprocessorDefinitions)  
	18.GO to Linker -> General -> Additional Libraries directories and edit it include $(SolutionDir)Dependencies\GLFW\lib-vc2015;$(SolutionDir)Dependencies\GLEW\lib\Release\Win32  
	19.Go to Linker -> Input -> Additional Dependencies. Remove everything from there and paste this - glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib;glew32s.lib  
	20.Now click ok and you should be good to go.  

	For further details follow this channel https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2
