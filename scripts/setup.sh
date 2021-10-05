export PATH="${PATH}:${PWD}/aqgc"
export PATH="${PATH}:${PWD}/fakephoton"
export PATH="${PATH}:${PWD}/make_datacard"
export PATH="${PATH}:${PWD}/make_datacard/python"
export PATH="${PATH}:${PWD}/make_datacard/bash"
export PATH="${PATH}:${PWD}/uncertainty"
export PATH="${PATH}:${PWD}/uncertainty/bash"
export PATH="${PATH}:${PWD}/condor"
export PATH="${PATH}:${PWD}/common"
export PATH="${PATH}:${PWD}/combine_scripts"
export PATH="${PATH}:${PWD}/unfolding"
export PATH="${PATH}:${PWD}/plot"
export PATH="${PATH}:${PWD}/breakdown"

export PYTHONPATH="$PYTHONPATH:${PWD}/uncertainty"
chmod +x aqgc/*py
chmod +x fakephoton/*py
chmod +x make_datacard/python/*py
chmod +x make_datacard/bash/*sh
chmod +x uncertainty/*py 
chmod +x uncertainty/bash/*sh
chmod +x condor/*py
chmod +x common/*
#chmod +x common/*sh
chmod +x combine_scripts/*sh
chmod +x unfolding/*py
chmod +x plot/*
chmod +x breakdown/*
