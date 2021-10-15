## :four::two: pipex project  
<hr style="border:2px solid gray"> </hr>  
The aim of this project is to reproduce the shell behavior of redirecting STDIN and STDOUT to files and emulating pipes.  
Execute command make and type the command listed below. The arguments will be processed as same as < infile cmd1 | cmd2 > outfile on the shell.  
```./pipex infile cmd1 cmd2 outfile ```  

### Objectives :computer:  
Your objective is to code the Pipex program.  
It should be executed in this way:  
```$> ./pipex file1 cmd1 cmd2 file2```<br/>
Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.  
The execution of the pipex program should do the same as the next shell command:  
```$> < file1 cmd1 | cmd2 > file2```  
### Examples :book:  
:keyboard:  
```$> ./pipex infile ''ls -l'' ''wc -l'' outfile```  
should be the same as ```< infile ls -l | wc -l > outfile```<br/>  
```$> ./pipex infile ''grep a1'' ''wc -w'' outfile```  
should be the same as ```< infile grep a1 | wc -w > outfile```  

<hr style="border:2px solid gray"> </hr>  

## Links <br/>
:link: pipex [subject](/subject/pipex.en.subject.pdf)  
:link: Nice explanatory [tutorial](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901)  
:link: [pipexMedic](https://github.com/gmarcha/pipexMedic) tester for pipex  
