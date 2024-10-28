pt="maps/standard/error/"
bt="maps/bonus/error/"

clear
printf "\033[95mDo you want compile with bonus?\033[0m \033[92m<y/n>\033[95m : \033[0m"
read makebonus

if [ "$makebonus" = "y" ];
then
	make bonus
elif [ "$makebonus" = "n" ];
then
	make
else
	printf "\033[92mBad format\033[0m"
fi

clear

if [ "$makebonus" = "n" ]; then
	./miniRT ${pt}err_amb_exists.rt
	echo ""
	./miniRT ${pt}err_invalid_normal.rt
	echo ""
	./miniRT ${pt}err_par_col.rt
	echo ""
	./miniRT ${pt}err_par_delim.rt
	echo ""
	./miniRT ${pt}err_par_ext.rttt
	echo ""
	./miniRT ${pt}err_par_ext2
	echo ""
	./miniRT ${pt}err_par_int.rt
	echo ""
	./miniRT ${pt}err_par_noid.rt
	echo ""
	./miniRT ${pt}err_par_real.rt
	echo ""
	./miniRT ${pt}err_par_unit.rt
	echo ""
	./miniRT ${pt}err_res_exists.rt
	echo ""
	./miniRT ${pt}err_res_neg.rt
	echo ""
	./miniRT ${pt}err_undef_cam.rt
	echo ""
	./miniRT ${pt}err_unused_param.rt
	echo ""
	./miniRT ${pt}err_vec_failure.rt
	echo ""
	./miniRT ${pt}warn_fov_range.rt
	echo ""
	./miniRT ${pt}warn_res_max_res.rt
	echo ""
	printf "\033[92mAll tests passed\033[0m"
elif [ "$makebonus" = "y" ];
then
	echo ""
	./miniRT ${bt}err_aa_exists.rt
	echo ""
	./miniRT ${bt}err_bad_mat.rt
	echo ""
	./miniRT ${bt}err_bad_obj.rt
	echo ""
	./miniRT ${bt}err_dof_type.rt
	echo ""
	./miniRT ${bt}err_missing_emis.rt
	echo ""
	./miniRT ${bt}err_missing_gmma.rt
	echo ""
	./miniRT ${bt}err_mix_textures.rt
	echo ""
	./miniRT ${bt}err_sky_exists.rt
	echo ""
	./miniRT ${bt}err_spp_neg.rt
	echo ""
	./miniRT ${bt}err_sun_exists.rt
	echo ""
	./miniRT ${bt}err_vp_scale.rt
	echo ""
	./miniRT ${bt}err_xpm_nofile.rt
	echo ""
	./miniRT ${bt}err_aa_samples.rt
	echo ""
	printf "\033[92mAll tests passed\033[0m"
else
	printf "\033[92mBad format\033[0m"
fi
