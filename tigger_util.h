/*
 *  tigger_util.h
 *  Tigger
 *
 *  Created by Dan Shipper on 6/21/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <getopt.h>

char * commit_hook = "#!/usr/bin/env ruby \n"
"require 'rubygems' \n"
"require 'grit' \n"
"include Grit \n"

"puts 'Running tigger....' \n"
"puts 'Matching tasks and commit messages.' \n"

"repo = Repo.new('./') \n"
"commits = repo.commits \n"

"tigger = File.new('.tigger', 'r') \n"
"tasks = Array.new \n"
"completed_tasks = Array.new \n"

"tigger.each_line { |line|  tasks << line } \n"

"tasks.each do | task | \n"
"commits.each do | commit | \n"                                                         
"if (commit.message.strip.upcase.index(task.strip.upcase) != nil) \n"
"completed_tasks << (Time.now.to_i.to_s + \"<?TIG?>\" + task) \n"
"tasks.delete task \n" 
"puts('Completed task: ' + task.strip + '.')\n "
"end \n"
"end  \n"  
"end\n "

"tigger.close\n "

"tigger = File.new('.tigger', 'w') \n"

"tasks.each { |task| tigger.write task } \n"

"tigger.close  \n"

"tigger_completed = File.new('.tigger_completed', 'a+') \n"
"completed_tasks.each { |task| tigger_completed.write task } \n"
"tigger_completed.close ";

char * tigger = "			                          _.- -.- -._     ..                                                 \n"
"			                             .;;'  .oe$$$eeu.. ,?;UU.                                        \n"
"   		                          ,+'!!  e$$$$$$$R$$$$x ?xd$)                                        \n"
"			                        ,'  !~ u$$$$F,$$$by,?$'e $F'        _ -                              \n"
"			              .,;,.   ,dm  :! $$$$$$d( )$( )?d$F       _ -       _                           \n"
"			             !?????X!!!!~!!!X!.'?????$$$F'.:::::::   -   .  - ~                              \n"
"			             +$$$$$m@`!!   ~? `!kCCU$$$$ ::::::::: g~  ~ -  _                                \n"
"			              '$BeCeW$:`~..__~x W$$$$$$$e `:::::'.$F           ~                             \n"
"			                '****'      ,``~~?$:=$$$$$$epppe$F`                                          \n"
"			                        , '   ,    ?W.''??$$FFF' *.                                          \n"
"			                      '     .     . ?$$e. ==+* ..$f                                          \n"
"			                   '     . '      H!.?$$$$$$$$$$$f                                           \n"
"			                      . '        !!!! ?$$$$$$$$$$                                            \n"
"			                             . ~!!!!!? ?$$$$$$$f.                                            \n"
"			                         . '     !!!!~*..****C.-!:..                                         \n"
"			                  . -  ~!!!:.    ?!!~.$$$$$$$$$$.!!!!:` .                                    \n"
"			             .- ~!::.    !!!!!.  ?X e$$$$$$$$$$$$.`!!!   .! - _                              \n"
"			         . `~!?: ~!!!!!  !!!!!!!!! $$$$$$$$$$$$$$$  !!   !!     !?                           \n"
"			        '      !!:!!!!!!!!!!!!!!!`:$$$$$$$$$$$$$$$U ~ :!!!!    !!~ `                         \n"
"			     .:::::...  !!!!!!!!~~~~!!!!X $$$$$$$$$$$$$$$$$  !!!!!...:&lt;~`   `                     \n"
"			    +   ~~!!!!!!!!~~     ::!!!!!':$$$$$$$$$$$$$$$$$~ *~~!!!!*`     .:!                       \n"
"			   ::::::::!!!!          '`~~!!~ *""$$$$$$$$$$$$$$$~       !!!!!!!!!``                       \n"
"			  ,'`~~!!!!!!~           :        u$$$$$$$$$$$$$$$$~       !!!!``'   ;                       \n"
"			 . .... ~!!!             .   ..+ $$$$$$$$$$$$$$$$$$~      .!!!!!!?:::-                       \n"
"			 !!!!!!!!!!!!::::+       !!~~~~~ **''$$$$$$$$$$$$$*    .+!!!!!!!!(  ,                        \n"
"			;!!!!!!!!!!!!!!!~        !!!::.. ue$$$$$$$$$$$$$$$~ !!!!!!!!!!!!!!!!                         \n"
"			!!!!!!!!!!!``            ~!!!!!! $$$$$$$$$$$$$$$$$     !!!!!!!!!!!!                          \n"
"			!!!!!!!!!!!             .   `~~! $$$$$$$$$$$$$$$$`    :!!!!!!!!!!X`                          \n"
"			~!!!!!!!!!!             ....::!! $$$$$$$$$$$$$$$$     !!!!!!!!!!~                            \n"
"			 `~!!!!!!!!             !!!!!!!!m$$$$$$$$$$$$$$$      !!!!!!!*`                              \n"
"			   `*~X!~*              !!!!!!!*:$$$$$$$$$$$$$$~      ``((`                                  \n"
"			                      :!!::   ` '?I$$$$$$$$$$$`                                              \n"
"			                      `~!!!!!- e$$$$$$$$$$$$$~                                               \n"
"			                   '     `*~! $$$$$$$$$$$$$$' .                                              \n"
"			                .:!:.     .: e$$$$$$$$$$$$$' ~  `                                            \n"
"			              '    `~!!!!!!~:$$$$$$$$$$$$* :*    :!       ......                             \n"
"			           ::::::..   ~!!!` $$$$$$$$$$$$':!~  :!!` `  .!!!!!!!!!!                            \n"
"			          -~!!!!!!!!::..!! 8$$$$$$$$$$*.!!!..!!~ ..- :!!!!!!!~!!!~                           \n"
"			        '     '~~!!!!!!!!! #$$$$$$$$*(!!!!!!!!!.+!~ :!!!!!~`- -`!                            \n"
												  "			      ;            `!!!!!!!.'*$$**' `````'`!!!!!!! !!!!!~                                    \n"
												  "			                ..  .!!!!!~~`               `!!!!`:!!!`        '                             \n"
												  "			      `.:!!!!!!!!!!!!!!~:                     !!!!!!!~       '                               \n"
												  "			       ~!!!!!!!~~`~!!!!!!:::                  ~!!!!!!      '                                 \n"
												  "			                .:!!!!!!!!!!!!:                `!!!!!_  '                                    \n"
												  "			              :::::::!?!!!!!!!!!                                                             \n"
												  "			           :!!!!!!!!!!!!!!!!!!~                                                              \n"
												  "			           `~!!!!!!!!!!!!!~~                                                                 \n"
												"\t\tTask Management is What Tiggers Do Best!\n" ;


typedef char * string;

const int COMMAND_SIZE = 7;
string commands[7];

/* flag settings */
static int COLOR_FLAG = 0;
static int FORCE_FLAG = 0;

static struct option long_options[] =
{
        { "color", no_argument, &COLOR_FLAG, 1 },
        { "force", no_argument, &FORCE_FLAG, 1 },
        { NULL, 0, 0, 0 }
};

/* ANSI Sequences, documented at
 * http://pueblo.sourceforge.net/doc/manual/ansi_color_codes.html */
const static char* ANSI_RESET                           = "\x1B[0m";
const static char* ANSI_FOREGROUND_COLOR_BLACK          = "\x1B[30m";
const static char* ANSI_FOREGROUND_COLOR_RED            = "\x1B[31m";
const static char* ANSI_FOREGROUND_COLOR_GREEN          = "\x1B[32m";
const static char* ANSI_FOREGROUND_COLOR_YELLOW         = "\x1B[33m";
const static char* ANSI_FOREGROUND_COLOR_BLUE           = "\x1B[34m";
const static char* ANSI_FOREGROUND_COLOR_MAGENTA        = "\x1B[35m";
const static char* ANSI_FOREGROUND_COLOR_CYAN           = "\x1B[36m";
const static char* ANSI_FOREGROUND_COLOR_WHITE          = "\x1B[37m";

/* color helper function prototypes -- not variadic for now */
int fprintf_color(FILE* stream, const char* str, const char* color);
int fprintf_black(FILE* stream, const char* str);
int fprintf_red(FILE* stream, const char* str);
int fprintf_green(FILE* stream, const char* str);
int fprintf_yellow(FILE* stream, const char* str);
int fprintf_blue(FILE* stream, const char* str);
int fprintf_magenta(FILE* stream, const char* str);
int fprintf_cyan(FILE* stream, const char* str);
int fprintf_white(FILE * stream, const char* str);
