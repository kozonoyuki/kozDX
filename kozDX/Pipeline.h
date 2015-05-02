/**
* @file   Pipeline.h
* @brief  �����_�[�p�C�v���C��
* @author kozonoyuki
* @date   12/25�ɏ����n��
*/

#pragma once
/*
�\�z�F
���Ƃ��΃V���h�E�}�b�v���쐬�������Ƃ��ɂ́A�V���h�E�}�b�v�쐬�A�V���h�E�}�b�v�Q�Ƃ������_�����O��
�Q�񃌃��_�����O���K�v�ł��邽�߁A���̃N���X�̃C���X�^���X���Q�쐬���ē��삳����
�K�v�ȋ@�\�F
�����_�[�^�[�Q�b�g�����肷��
�I�u�W�F�N�g���i�[����
�f�v�X�X�e���V���r���[�����肷��
�u�����h�X�e�[�g�����肷��
�r���[�|�[�g��ݒ肷�� -> ��̗̈�H�@-> �ʂɐݒ���s�����߂��̗̈�H
�I�u�W�F�N�g��`�悷��
private�e�X�g
*/

namespace koz
{
	/**
	* @brief �p�C�v���C���N���X
	*/
	class Pipeline
	{
	private:
		/**
		* �I�u�W�F�N�g�f�[�^
		*/
		std::vector<std::shared_ptr<Object>> m_ObjectSoup;
	public:
		/**
		* �f�t�H���g�R���X�g���N�^
		*/
		Pipeline();

		/**
		* �f�X�g���N�^
		*/
		~Pipeline();
	};
}