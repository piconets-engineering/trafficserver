# lib Makefile.am
#
#  Licensed to the Apache Software Foundation (ASF) under one
#  or more contributor license agreements.  See the NOTICE file
#  distributed with this work for additional information
#  regarding copyright ownership.  The ASF licenses this file
#  to you under the Apache License, Version 2.0 (the
#  "License"); you may not use this file except in compliance
#  with the License.  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

SUBDIRS = . records fastlz swoc

if BUILD_PERL_LIB
SUBDIRS += perl
endif

# to prevent Clang Analyzer warning
LOCAL =

if BUILD_YAML_CPP
LOCAL += yamlcpp
endif

all-local:	$(LOCAL)
	$(MAKE) -C yamlcpp

clean-local:
	$(MAKE) -C yamlcpp clean

if EXPORT_YAML_HEADERS
install-data-local:
	$(MAKE) -C yamlcpp install
endif
